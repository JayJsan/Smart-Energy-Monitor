function [RMSValue] = RMSCalc(array)
%RMSCALC Summary of this function goes here
%   Detailed explanation goes here

sum = 0;
for i = 1:length(array)
    sum = sum + array(i) ^2; 
end
RMSValue = sum / 80;
RMSValue = sqrt(RMSValue);
end

