//
// Created by Baptiste WETTERWALD on 18/12/2023.
//

#ifndef ECOLE_CPP_F_TIMESERIESGENERATOR_H
#define ECOLE_CPP_F_TIMESERIESGENERATOR_H

#include <vector>
using namespace std;

class TimeSeriesGenerator {
public:
    TimeSeriesGenerator(int seed);
    virtual vector<double> generateTimeSeries(int size) = 0;
    static void printTimeSeries(vector<double> timeSeries);
protected:
    int seed;
};


#endif //ECOLE_CPP_F_TIMESERIESGENERATOR_H
