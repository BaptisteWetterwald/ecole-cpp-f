//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#include <cmath>
#include "SinWaveGenerator.h"

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> timeSeries;

    for (int i = 0; i < size; i++) {
        timeSeries.push_back(amplitude * sin(frequency * i + phase));
    }

    return timeSeries;
}

SinWaveGenerator::SinWaveGenerator(int seed, double amplitude, double frequency, double phase) : TimeSeriesGenerator(seed){
    this->amplitude = amplitude;
    this->frequency = frequency;
    this->phase = phase;
}
