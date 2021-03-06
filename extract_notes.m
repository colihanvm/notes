% radius = 5.4;
% num_find = 19;
% threshold = 155;
% im = imread('img/rowrowbt_mod3.png');
% im = imread('img/lond_mod2.jpg');
function [notes] = extract_notes(im, threshold, num_find, radius)

im = rgb2gray(im);

for i=1:size(im,1)
    for j=1:size(im,2)
        if im(i,j) > 240
            im(i,j) = 255;
        end
    end
end

%% 

double_im = double(im);
tmp = sum(double_im, 2);


mean_val = sum(tmp)/size(tmp,1);
std_val = std(tmp);
threshold_val = mean_val - 2 * std_val;

ind = find(tmp < threshold_val);

%actually delete the staffs
im(ind, :) = 255;

%% 

%TODO: preallocate the proper amount of staff lines
%calculate staff lines
staffs = zeros(10,1);
staffs(1) = ind(1);
lines = zeros(size(ind));
j = 1;
num = 1;
lines(1) = 1;
staff_num = zeros(size(staffs));
staff_num(1) = 1;

for i=2:size(ind,1)
    if (ind(i) > (ind(i-1) + 1)) %end line deletion
        
        staffs(j) = floor(staffs(j) / num);
        num = 1;
        
        j = j + 1;
        
        staffs(j) = ind(i); %first line
        lines(i) = j;
        staff_num(j) = staff_num(j) + 1;
    else
        staffs(j) = staffs(j) + ind(i); %there was a line deleted above this
        lines(i) = j;
        staff_num(j) = staff_num(j) + 1;
        num = num + 1;
        if i == size(ind,1) %last
            staffs(j) = floor(staffs(j) / num);
        end
        
    end
end

%%

%GAP STITCHING:

%lines array contains index of staffs that were removed, matches ind array
%staff_num tells number of horiz lines deleted around this staff
all_notes = im(:);
note_threshold = floor(sum(all_notes)/(size(all_notes,1))) - 2 * std(double(all_notes));
lines_passed = 1; %will give current index of ind array (y pos of all staff part lines detected)

staff_heights = zeros(size(staffs,1) - size(staffs,1)/5, 1);
h = 1;
for s=1:size(staffs,1) %y values of staffs. s = index of staffs AKA staff number
    above_s = ind(lines_passed)-1;
    below_s = ind(lines_passed) + staff_num(s); %ind(lines_passed) + staff_num(s)-1 + 1;
    for x=1:size(im,2) %x pos of image
        
        if (im(above_s, x) < note_threshold)
            if(im(below_s, x) < note_threshold)
                im(ind(lines_passed):(ind(lines_passed + staff_num(s) - 1)), x) = floor((im(above_s, x) + im(below_s, x))/2);
            elseif (im(above_s, x) < note_threshold)
                im(ind(lines_passed):(ind(lines_passed + staff_num(s) - 1)), x) = floor((im(above_s, x))*1.5);
            end
        elseif(im(below_s, x) < note_threshold)
            im(ind(lines_passed):(ind(lines_passed + staff_num(s) - 1)), x) = floor((im(below_s, x))*1.5);
        end
        
        
    end
    lines_passed = lines_passed + staff_num(s);
    if (s>1)
        if (mod(s,6) ~= 0)
            staff_heights(h) = staffs(s) - staffs(s-1);
            h = h + 1;
        end
    end
end

avg_staff_height = sum(staff_heights)/size(staff_heights,1);


%%

%do work by chunks in this section

% radius = 5.4; %pretty good for 4th, 8th
% num = 19; 
acc = 1;

%%%%%%%%%%%%%% TO DO: preallocate centers array 
centers = [];

%remove vertical lines by stanza, using process_stanza() function.
num_stanza = size(staffs,1)/5;
for stanza=1:num_stanza
    blank = uint8(255 * ones(size(im)));
    chunk_start = max(staffs(1 + (stanza - 1) * 5) - floor(2 * avg_staff_height),1);
    chunk_end = staffs(5 + (stanza - 1) * 5) + floor(2 * avg_staff_height);
    im_chunk = im(chunk_start:chunk_end, :);
    im_chunk = process_stanza(im_chunk);
    
    blank(chunk_start:chunk_end, :) = im_chunk;
    edges = detectEdges_removeLines(blank, threshold, 0);
    chunk_centers = detectCircles(blank, edges, radius, num_find, acc);
   
    %sort by x
    [~, sort_ind] = sort(chunk_centers(:,1));
    chunk_centers = chunk_centers (sort_ind,:);
    
    %post processing of this chunk
    %first, remove the random perimeter circles that tend to pop up
    chunk_centers(chunk_centers(:,1) > size(im,2) - radius, :) = [];
    chunk_centers(chunk_centers(:,2) > size(im,1) - radius, :) = [];
    
    chunk_centers(chunk_centers(:,1) < radius, :) = [];
    chunk_centers(chunk_centers(:,2) < radius, :) = [];
    
    extras = false(size(chunk_centers,1), 1);
    %check every circle c:
    for c=2:size(chunk_centers,1)
        if (chunk_centers(c,1) == chunk_centers(c-1,1))
            extras(c) = 1;
        elseif (abs(chunk_centers(c,1) - chunk_centers(c-1,1)) < radius*2)
            if (sort_ind(c) < sort_ind(c-1))
                extras(c-1) = 1;
            else
                extras(c) = 1;
            end
        end
    end
    %remove the circles we just flagged
    chunk_centers(extras,:) = [];

    %final post processing
    %TODO: better benchmarks
    for c=1:size(chunk_centers,1)         
        top = sum(blank(chunk_centers(c,2)-floor(radius):chunk_centers(c,2),chunk_centers(c,1)));
        bottom = sum(blank(chunk_centers(c,2):chunk_centers(c,2)+floor(radius),chunk_centers(c,1)));
        left = sum(blank(chunk_centers(c,2),chunk_centers(c,1)-floor(radius):chunk_centers(c,1)));
        right = sum(blank(chunk_centers(c,2),chunk_centers(c,1):chunk_centers(c,1)+floor(radius)));
        if (top-bottom < -900)
            chunk_centers(c,:) = [chunk_centers(c,1), chunk_centers(c,2) - radius/2];
        elseif (top-bottom < -500)
            chunk_centers(c,:) = [chunk_centers(c,1), chunk_centers(c,2) - radius/2];
        elseif (top-bottom > 900)
            chunk_centers(c,:) = [chunk_centers(c,1), chunk_centers(c,2) + radius/2];
        elseif (top-bottom > 500)
            if (left-right > 900)
                %check for tangential half note
                if (blank(chunk_centers(c,2) + floor(radius*0.7), chunk_centers(c,1) + floor(radius*0.7)) > 200)
                     chunk_centers(c,:) = [chunk_centers(c,1) + radius/2, chunk_centers(c,2) + radius/2];
                end
            end
            
        elseif (top == bottom && blank(chunk_centers(c,2),chunk_centers(c,1)) == 255)
            chunk_centers(c,:) = [chunk_centers(c,1)+1, chunk_centers(c,2)];
            top = sum(blank(chunk_centers(c,2)-floor(radius):chunk_centers(c,2),chunk_centers(c,1)));
            bottom = sum(blank(chunk_centers(c,2):chunk_centers(c,2)+floor(radius),chunk_centers(c,1)));
            if (top-bottom < -900)
                chunk_centers(c,:) = [chunk_centers(c,1), chunk_centers(c,2) - radius/2];
            elseif (top-bottom > 900)
                chunk_centers(c,:) = [chunk_centers(c,1), chunk_centers(c,2) + radius/2];
            end
        end
    end
  
    centers = [centers; chunk_centers];
    im(chunk_start:chunk_end, :) = im_chunk;
end

% x=1:size(im,2);
% figure; imshow(og)
% viscircles(centers, radius * ones(size(centers, 1), 1)); hold on
% plot(x, staffs*ones(size(x)));

%%
% create full staffs and etc.
%TODO: preallocate full_staffs for 1 or 2 stanzas
full_staffs = zeros((size(staffs,1) + 3) * (size(staffs,1)/5),1);
scale = ['A6';'G5';'F5';'E5';'D5';'C5';'B5';'A5';'G4';'F4';'E4';'D4';'C4'];
num_stanza = size(full_staffs,1)/size(scale,1);
full_scale = repmat(scale, num_stanza, 1);

for stanza=1:num_stanza
    full_start = 1 + (size(scale,1) * (stanza-1));
    staff_start = 1 + (size(staffs,1)/num_stanza * (stanza-1));
    
    full_staffs(full_start) = staffs(staff_start)-avg_staff_height; %A5
    full_staffs(full_start + 1) = staffs(staff_start)-avg_staff_height/2; %G5
    l = staff_start;
    for p = full_start + 2:full_start + 10
        if mod(p + stanza-1,2)
            full_staffs(p) = staffs(l);
        else
            full_staffs(p) = staffs(l) + avg_staff_height/2;
            l = l + 1;
        end
    end
    full_staffs(full_start + 11) = staffs(staff_start + 4)+avg_staff_height/2; %D4
    full_staffs(full_start + 12) = staffs(staff_start + 4)+avg_staff_height; %C4
end

%%

% get those letters

notes = char(ones(size(centers,1),1) * '00');

for i=1:size(centers,1)
    diff = full_staffs - centers(i,2);
    [~, min_in] = min(abs(diff));

    notes(i,:) = full_scale(min_in,:);
end

end