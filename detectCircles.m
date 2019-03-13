function [centers] = detectCircles(im, edges, radius, top_k, ~)

centers = zeros(top_k, 2);
quant_val = 5;
H = zeros(size(im,1), size(im,2));

for i=1:size(edges,1) %over every edge
    %[x, y, mag, ori] = edges(i, :);
    x = edges(i, 1); y = edges(i, 2); theta = edges(i, 4);

    a = x - radius * cosd(theta);
    b = y - radius * sind(theta);
    a = ceil(a/quant_val);
    b = ceil(b/quant_val);
    if (a>0 && b>0)
        H(a,b) = H(a,b) + 1;
    end 
end

H_sort = sort(H(:), 'descend');
repeat = 2;
for i=1:top_k
    [row, col] = find(H == H_sort(i));
    if (i > 1 && H_sort(i) == H_sort(i-1))
        centers(i,1) = row(repeat);
        centers(i,2) = col(repeat);
        repeat = repeat + 1;
    else
        repeat = 2;
        centers(i,1) = row(1);
        centers(i,2) = col(1);
    end 
end
centers = centers*quant_val;
