function [biggerArray] = Proper_Implementation_V(array)
%PROPER_IMPLEMENTATION Summary of this function goes here
%   Detailed explanation goes here

arrayLength = length(array);


for j = 1:arrayLength-1
    biggerArray(j) = (array(j) + array(j+1)) / 2;

end
biggerArray(arrayLength) = ((biggerArray(arrayLength - 1)*2) + biggerArray(arrayLength - 1) )/2;


end

