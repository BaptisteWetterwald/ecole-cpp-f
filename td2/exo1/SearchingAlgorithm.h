//
// Created by Baptiste  WETTERWALD on 16/11/2023.
//

#ifndef ECOLE_CPP_F_SEARCHINGALGORITHM_H
#define ECOLE_CPP_F_SEARCHINGALGORITHM_H

#include <vector>
#include <iostream>
#include <sstream>

class SearchingAlgorithm {
public:
    int numberComparisons = 0;
    static int totalSearch;
    static int totalComparisons;
    static double averageComparisons;

    SearchingAlgorithm();

    virtual int search(const std::vector<int>& arr, int target) = 0;

    virtual void displaySearchResults(std::ostream& os, int result, int target) = 0;
};

#endif //ECOLE_CPP_F_SEARCHINGALGORITHM_H
