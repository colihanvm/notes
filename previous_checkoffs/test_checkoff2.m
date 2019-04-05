close all;

threshold = 150;
im = imread('rowrowbt_mod3.png');
im = rgb2gray(im);

for i=1:size(im,1)
    for j=1:size(im,2)
        if im(i,j) > 240
            im(i,j) = 255;
        end
    end
end
%figure; imshow(im); title('pixel color adjust');

double_im = double(im);
tmp = sum(double_im, 2);
figure; plot(tmp);  title('row sum');

pause;

ind = find(tmp < 147000);
im(ind, :) = 255;
figure; imshow(im); title('lines erased');

pause;

%calculate staff lines
staffs = zeros(10,1);
staffs(1) = ind(1);
j = 1;
num = 1;
for i=2:size(ind,1)
    if (ind(i) > (ind(i-1) + 1))
        staffs(j) = staffs(j) / num;
        num = 1;
        j = j + 1;
        staffs(j) = ind(i);
    else
        staffs(j) = staffs(j) + ind(i);
        num = num + 1;
        if i == size(ind,1)
            staffs(j) = staffs(j) / num;
        end
    end
end

figure; imshow(im); title('visualization of staff lines'); hold on
plot(x, staffs*ones(size(x)));

pause;

radius = 7; %pretty good for 4th, 8th
num = 25; 
edges = detectEdges_removeLines(im, threshold, 1);
acc = 15/27;
centers = detectCircles(im, edges, radius, num, acc);

[~, in] = sort(centers(:,2));
centers = centers (in,:);
centers(13:15,:) = []; %change to remove based on staff lol
%also check for stacked circles (works if no chords)

figure; imshow(im); title(strcat('Detected circles of radius=', num2str(radius), ', accuracy=', num2str(acc)));
viscircles(centers, radius * ones(size(centers, 1), 1));

% NEXT PART:
scale = ['F';'D';'B';'G';'E'];
scale = repmat(scale, size(staffs,1)/size(scale,1), 1);
x=1:size(im,2);

% notes = zeros(size(centers,1),1);
% for i=1:size(centers,1)
%      notes(i)=closest_to(centers(i,2),staffs,scale); 
% end