function [superBigArrayC] = interlaceCurrent(CurrentLA,current)
%INTERLACECURRENT Summary of this function goes here
%   Detailed explanation goes here
    j = 1;
    for i = 1:length(CurrentLA)
        superBigArrayC(j) = CurrentLA(i);
        j = j + 1;
        superBigArrayC(j) = current(i);
        j = j + 1;
    end
end

