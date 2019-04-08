function [im_chunk] = process_stanza(im_chunk)

% original chunk
% figure; imshow(im_chunk)

%calculate column sum over the stanza
tmp = sum(double(im_chunk), 1)';
%  figure; plot(tmp);  title('col sum');

%find value to threshold with
mean_val = sum(tmp)/size(tmp,1);
std_val = std(tmp);
threshold_val = mean_val - 2 * std_val;

%select vertical bits
ind = tmp < threshold_val;

%delete vertical bits
im_chunk(:, ind) = 255;

%find nasty flags
max_val = tmp(1); %max(tmp);
del = 0;
last = -1;
same = 0;
for i=1:size(ind,1)-1
    if (del) %last index was deleted or was rightmost edge
        if (tmp(i) < max_val)
            if (same)
                if (tmp(i) ~= last)
                    del = 0;
                end
            end
            if (tmp(i) == last)
                same = 1;
            end
            im_chunk(:, i) = 255;
            last = tmp(i);
        else
            del = 0;
        end
        
    elseif (ind(i) && ~ind(i+1)) %find rightmost edge of a vert line
        del = 1;
        same = 0;
    end
end

%the result!
% figure; imshow(im_chunk)
end