function [RMSValue] = RMSCalc(array)
%RMSCALC Summary of this function goes here
%   Detailed explanation goes here

sum = 0;
for i = 1:length(array)
    sum = sum + (array(i)*array(i) * 0.000108); 
    test = array(i)*array(i)*0.000108;
end

RMSValue = (1/(80*0.000108))*sum;
RMSValue = sqrt(RMSValue);

end

