%notes(i)=closest_to(centers(i,2),staffs,scale); 
function [note] = closest_to(y, staffs, scale)

%note = '0';

diff = staffs - y;
less = abs(diff)<5;
score = sum(less);

if score == 1
    if scale(less)=='E'
        if y > staff + 2
            note = '0';
        else
            note = strcat(scale(less),'0');
        end
    end
elseif score == 2
    note = scale(less);
    note = strcat(note(1),note(2));
else
    note = '0';
end

end

