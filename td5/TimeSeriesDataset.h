//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#ifndef ECOLE_CPP_F_TIMESERIESDATASET_H
#define ECOLE_CPP_F_TIMESERIESDATASET_H

#include <vector>

using namespace std;

class TimeSeriesDataset {
public:
    bool znormalize;
    bool isTrain;
    vector<vector<double>> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;

    TimeSeriesDataset(bool znormalize, bool isTrain);
    void addTimeSeries(vector<double> timeSeries);
    void printDataset();
};


#endif //ECOLE_CPP_F_TIMESERIESDATASET_H
