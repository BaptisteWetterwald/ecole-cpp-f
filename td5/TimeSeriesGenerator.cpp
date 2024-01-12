//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#include <iostream>
#include "TimeSeriesGenerator.h"

void TimeSeriesGenerator::printTimeSeries(vector<double> timeSeries) {
    cout << "Time Series: [";
    for (int i = 0; i < timeSeries.size(); i++) {
        cout << timeSeries[i];
        if (i != timeSeries.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

TimeSeriesGenerator::TimeSeriesGenerator(int seed) {
    this->seed = seed;
}
