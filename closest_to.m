%C4-A5

%notes(i,:)=closest_to(centers(i,2),full_staffs,full_scale, avg_staff_height); 
function [note] = closest_to(y, staffs, scale, avg_staff_height)
%     note = '00';
    diff = staffs - y;
%     less = abs(diff)<avg_staff_height/2;
%     score = sum(less);
    [~, min_in] = min(abs(diff));

    note = scale(min_in,:);
%     if score == 1
%         note = scale(less,:);
%     elseif score > 1
%         note = scale(min_in,:);
%     end
end

