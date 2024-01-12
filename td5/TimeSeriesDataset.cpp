//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#include <iostream>
#include <cmath>
#include "TimeSeriesDataset.h"

void TimeSeriesDataset::printDataset() {
    cout << "Dataset: " << endl;
    for (int i = 0; i < data.size(); i++) {
        cout << "Time Series " << i << ": [";
        for (int j = 0; j < data[i].size(); j++) {
            cout << data[i][j];
            if (j != data[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "] - Label: " << labels[i] << endl;
    }
}

void TimeSeriesDataset::addTimeSeries(vector<double> timeSeries) {
    if (znormalize){
        double mean = 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            mean += timeSeries[i];
        }
        mean /= timeSeries.size();

        double std = 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            std += pow(timeSeries[i] - mean, 2);
        }
        std /= timeSeries.size();
        std = sqrt(std);

        for (int i = 0; i < timeSeries.size(); i++) {
            timeSeries[i] = (timeSeries[i] - mean) / std;
        }
    }
    else{
        double max = 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            if (timeSeries[i] > max){
                max = timeSeries[i];
            }
        }

        for (int i = 0; i < timeSeries.size(); i++) {
            timeSeries[i] /= max;
        }
    }
}

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain) {
    this->znormalize = znormalize;
    this->isTrain = isTrain;
    this->maxLength = 0;
    this->numberOfSamples = 0;
}
