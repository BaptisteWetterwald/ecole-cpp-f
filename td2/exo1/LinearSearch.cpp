//
// Created by Baptiste  WETTERWALD on 16/11/2023.
//

#include "LinearSearch.h"

int LinearSearch::search(const std::vector<int> &arr, int target) {
    totalSearch++;
    numberComparisons = 0;
    for (int i = 0; i < arr.size(); i++) {
        numberComparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}