function [SuperBigArrayV] = interlaceVoltage(voltage, voltageLA)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    j = 1;
    
    for i = 1:length(voltageLA)
        SuperBigArrayV(j) = voltage(i);
        j = j + 1;
        SuperBigArrayV(j) = voltageLA(i);
        j = j + 1;
    end
end

