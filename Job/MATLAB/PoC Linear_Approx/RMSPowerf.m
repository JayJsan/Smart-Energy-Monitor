function [RMSPowerOut] = RMSPowerf(voltage, voltageLCalc, current, currentLCalc)
%RMSPOWER Summary of this function goes here
%   Detailed explanation goes here
    
    test = 0;
    
    for i = 1:length(voltage)
        test = test + ((voltage(i) * currentLCalc(i)) + (voltageLCalc(i) * current(i)));
    
    end

    RMSPowerOut = (test/(2 * 27))/1000000;
end

