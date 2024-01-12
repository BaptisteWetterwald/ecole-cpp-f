//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#ifndef ECOLE_CPP_F_SINWAVEGENERATOR_H
#define ECOLE_CPP_F_SINWAVEGENERATOR_H


#include "TimeSeriesGenerator.h"

class SinWaveGenerator : public TimeSeriesGenerator {
public:
    SinWaveGenerator(int seed, double amplitude, double frequency, double phase);
    vector<double> generateTimeSeries(int size) override;
private:
    double amplitude;
    double frequency;
    double phase;
};


#endif //ECOLE_CPP_F_SINWAVEGENERATOR_H
