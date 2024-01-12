//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#include <cstdlib>
#include <cmath>
#include "GaussianGenerator.h"

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> timeSeries;
    srand(seed);
    for (int i = 0; i < size; i++) {
        double u1 = (double) rand() / RAND_MAX;
        double u2 = (double) rand() / RAND_MAX;
        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        double z1 = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);
        timeSeries.push_back(mean + standardDeviation * z0);
        timeSeries.push_back(mean + standardDeviation * z1);
    }
    return timeSeries;
}

GaussianGenerator::GaussianGenerator(int seed, double mean, double standardDeviation) : TimeSeriesGenerator(seed) {
    this->mean = mean;
    this->standardDeviation = standardDeviation;
}

GaussianGenerator::GaussianGenerator(int seed) : TimeSeriesGenerator(seed) {

}
