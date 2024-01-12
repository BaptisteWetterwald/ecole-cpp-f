//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#include <iostream>
#include "TimeSeriesGenerator.h"
#include "GaussianGenerator.h"
#include "StepGenerator.h"
#include "SinWaveGenerator.h"
#include "TimeSeriesDataset.h"

int main() {
    GaussianGenerator gaussianGenerator(0);
    vector<double> gaussian = gaussianGenerator.generateTimeSeries(10);
    TimeSeriesGenerator::printTimeSeries(gaussian);

    cout << endl;

    StepGenerator stepGenerator(0);
    vector<double> step = stepGenerator.generateTimeSeries(10);
    TimeSeriesGenerator::printTimeSeries(step);

    cout << endl;

    SinWaveGenerator sinWaveGenerator(0, 1, 1, 0);
    vector<double> sinWave = sinWaveGenerator.generateTimeSeries(10);
    TimeSeriesGenerator::printTimeSeries(sinWave);

    TimeSeriesDataset timeSeriesDataset(true, true);
    timeSeriesDataset.addTimeSeries(gaussian);
    timeSeriesDataset.addTimeSeries(step);
    timeSeriesDataset.addTimeSeries(sinWave);

    timeSeriesDataset.printDataset();
    return 0;
}