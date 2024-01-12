//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#include <cstdlib>
#include <iostream>
#include "StepGenerator.h"

StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {}

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> timeSeries;

    timeSeries.push_back(0);

    for (int i = 1; i < size; i++) {
        if (rand() % 2 == 0) {
            int rdm = (int) (rand() % 101);
            timeSeries.push_back(rdm);
        } else {
            timeSeries.push_back(timeSeries[i - 1]);
        }

    }

    return timeSeries;
}
