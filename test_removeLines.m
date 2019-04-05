close all;

threshold = 155;
im = imread('rowrowbt_mod3.png');
im = rgb2gray(im);
og = im;
for i=1:size(im,1)
    for j=1:size(im,2)
        if im(i,j) > 240
            im(i,j) = 255;
        end
    end
end


% 
%  figure; imshow(im); title('pixel color adjust');

%% 

double_im = double(im);
tmp = sum(double_im, 2);
%  figure; plot(tmp);  title('row sum');
% 
% pause;
mean_val = sum(tmp)/size(tmp,1);
std_val = std(tmp);
threshold_val = mean_val - 2 * std_val;

ind = find(tmp < threshold_val); %147000);%

%actually delete the staffs
im(ind, :) = 255;

%figure; imshow(im); title('lines erased');
 
%pause;

%% 

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


% figure; imshow(im); title('visualization of no staff lines'); hold on
%pause;

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
                im(ind(lines_passed):(ind(lines_passed + staff_num(s) - 1)), x) = floor((im(above_s, x))/2);
            end
        elseif(im(below_s, x) < note_threshold)
            im(ind(lines_passed):(ind(lines_passed + staff_num(s) - 1)), x) = floor((im(below_s, x))/2);
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

% figure; imshow(im); title('visualization of slightly more lines'); hold on



% figure; imshow(im); title('visualization of staff lines'); hold on
% plot(x, staffs*ones(size(x)));
% 
% pause;


%%

radius = 5.4; %pretty good for 4th, 8th
num = 19; 
acc = 25/27;

%%%%%%%%%%%%%% TO DO: preallocate centers array 
centers = [];
x=1:size(im,2);
blank = uint8(255 * ones(size(im)));
%remove vertical lines by stanza, using process_stanza() function.
num_stanza = size(staffs,1)/5;
for stanza=1:num_stanza
    blank = uint8(255 * ones(size(im)));
    chunk_start = staffs(1 + (stanza - 1) * 5);
    chunk_end = staffs(5 + (stanza - 1) * 5) + 2 * avg_staff_height;
    im_chunk = im(chunk_start:chunk_end, :);
    im_chunk = process_stanza(im_chunk);
    
    blank(chunk_start:chunk_end, :) = im_chunk;

    edges = detectEdges_removeLines(blank, threshold, 0);
    
    chunk_centers = detectCircles(blank, edges, radius, num, acc);
    %sort by x
    [~, sort_ind] = sort(chunk_centers(:,1));
    chunk_centers = chunk_centers (sort_ind,:);
    
    %first, remove the random perimeter circles that tend to pop up
    chunk_centers(chunk_centers(:,1) > size(im,2) - radius, :) = [];
    chunk_centers(chunk_centers(:,2) > size(im,1) - radius, :) = [];
    
    extras = false(size(chunk_centers,1), 1);
    
%     figure; imshow(blank)
%     viscircles(chunk_centers, radius * ones(size(chunk_centers, 1), 1)); hold on

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
    chunk_centers(extras,:) = [];
    
    naughty = zeros(size(chunk_centers,1),1);
    
    %final post processing
    %TODO: better benchmarks
    for c=1:size(chunk_centers,1)         
        top = sum(blank(chunk_centers(c,2)-floor(radius):chunk_centers(c,2),chunk_centers(c,1)));
        bottom = sum(blank(chunk_centers(c,2):chunk_centers(c,2)+floor(radius),chunk_centers(c,1)));
        if (top-bottom < -900)
            chunk_centers(c,:) = [chunk_centers(c,1), chunk_centers(c,2) - radius/2];
            naughty(c) = top-bottom;
        elseif (top-bottom < -500)
            chunk_centers(c,:) = [chunk_centers(c,1), chunk_centers(c,2) - radius/5];
            naughty(c) = top-bottom;
        elseif (top-bottom > 900)
            chunk_centers(c,:) = [chunk_centers(c,1), chunk_centers(c,2) + radius/2];
            naughty(c) = top-bottom;
        elseif (top == bottom && blank(chunk_centers(c,2),chunk_centers(c,1)) == 255)
            chunk_centers(c,:) = [chunk_centers(c,1)+1, chunk_centers(c,2)];
            top = sum(blank(chunk_centers(c,2)-floor(radius):chunk_centers(c,2),chunk_centers(c,1)));
            bottom = sum(blank(chunk_centers(c,2):chunk_centers(c,2)+floor(radius),chunk_centers(c,1)));
            if (top-bottom < -900)
                chunk_centers(c,:) = [chunk_centers(c,1), chunk_centers(c,2) - radius/2];
                naughty(c) = top-bottom;
            elseif (top-bottom > 900)
                chunk_centers(c,:) = [chunk_centers(c,1), chunk_centers(c,2) + radius/2];
                naughty(c) = top-bottom;
            end
        end
    end
  
%     figure; imshow(blank)
%     viscircles(chunk_centers, radius * ones(size(chunk_centers, 1), 1)); hold on    

    centers = [centers; chunk_centers];
    im(chunk_start:chunk_end, :) = im_chunk;
end

% figure; imshow(og)
% viscircles(centers, radius * ones(size(centers, 1), 1)); hold on
% plot(x, staffs*ones(size(x)));

%%
% create full staffs and etc.

full_staffs = zeros((size(staffs,1) + 3) * (size(staffs,1)/5),1);
% scale = ['F';'D';'B';'G';'E'];
scale = ['A5';'G5';'F5';'E5';'D5';'C5';'B4';'A4';'G4';'F4';'E4';'D4';'C4'];
num_stanza = size(full_staffs,1)/size(scale,1);
full_scale = repmat(scale, num_stanza, 1);
pitch = 3;
line = 1;
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
     notes(i,:)=closest_to(centers(i,2), full_staffs, full_scale, avg_staff_height); 
end