function [RMSPowerOut] = RMSPowerSecond(powergraph)
%RMSPOWER Summary of this function goes here
%   Detailed explanation goes here
    
    test = 0;
    
    for i = 1:length(powergraph)
        test = test + (powergraph(i));
    
    end

    RMSPowerOut = (test/(2 * 55));
end

