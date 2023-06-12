function [biggerArray] = Proper_Implementation_C(array)
%PROPER_IMPLEMENTATION Summary of this function goes here
%   Detailed explanation goes here

arrayLength = length(array);

biggerArray(1) = (0 + array(1))/2;

for j = 2:arrayLength
    biggerArray(j) = (array(j-1) + array(j)) / 2;
    

end


end

