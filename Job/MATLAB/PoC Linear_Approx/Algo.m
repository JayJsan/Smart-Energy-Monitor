function [biggerArray] = Algo(array)
%ALGO Summary of this function goes here
%   Detailed explanation goes here

arrayLength = length(array);
biggerArray = zeros(1, arrayLength*2);
biggerArrayLength = length(biggerArray);


%array(41) = array(40) *2;

i = 1;
for j = 1:arrayLength
    biggerArray(2*j-1) = array(j) 
end

for j = 1:biggerArrayLength - 1
    if(biggerArray(j) == 0)
        biggerArray(j) = (biggerArray(j-1) + biggerArray(j+1))/2
    end
% for j = 1:arrayLength-1
%     if (mod(j, 2) == 0)
%         biggerArray(i) = (array(j) + array(j+1)) / 2;
%         biggerArray(i+1) = array(j);
%         i = i + 1;
%     else
%         biggerArray(i) = array(j);
%     end
%     i=i+1;
% end

end

