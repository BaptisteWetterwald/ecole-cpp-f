//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#ifndef ECOLE_CPP_F_GAUSSIANGENERATOR_H
#define ECOLE_CPP_F_GAUSSIANGENERATOR_H


#include "TimeSeriesGenerator.h"

class GaussianGenerator : public TimeSeriesGenerator {
public:
    GaussianGenerator();
    GaussianGenerator(int seed);
    GaussianGenerator(int seed, double mean, double standardDeviation);
    vector<double> generateTimeSeries(int size) override;
private:
    double mean;
    double standardDeviation;
};


#endif //ECOLE_CPP_F_GAUSSIANGENERATOR_H
