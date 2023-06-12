function [biggerArray] = Algo2(array)
%ALGO Summary of this function goes here
%   Detailed explanation goes here
%THIS IS FOR CURRENT
arrayLength = length(array);
biggerArray = zeros(1, arrayLength*2);
biggerArrayLength = length(biggerArray);

%array(41) = array(40) *2;

i = 1;
for j = 1:arrayLength
    biggerArray(2*j) = array(j) 
end

for j = 1:biggerArrayLength - 1
    if(j ~= 1)
        if(biggerArray(j) == 0)
            biggerArray(j) = (biggerArray(j-1) + biggerArray(j+1))/2
    
        end
    end
end

