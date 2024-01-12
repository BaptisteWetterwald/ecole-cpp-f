//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#ifndef ECOLE_CPP_F_STEPGENERATOR_H
#define ECOLE_CPP_F_STEPGENERATOR_H


#include "TimeSeriesGenerator.h"

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    StepGenerator(int seed);
    StepGenerator(int seed, double stepSize);
    vector<double> generateTimeSeries(int size) override;
};


#endif //ECOLE_CPP_F_STEPGENERATOR_H
