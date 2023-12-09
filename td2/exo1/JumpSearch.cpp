//
// Created by Baptiste  WETTERWALD on 16/11/2023.
//

#include "JumpSearch.h"
#include <vector>
#include <cmath>

int JumpSearch::search(const std::vector<int> &arr, int target) {
    totalSearch++;
    numberComparisons = 0;
    int n = (int)arr.size();
    int step = (int) sqrt(n);
    int prev = arr[0];
    while (arr[std::min(step, n) - 1] < target) {
        numberComparisons++;
        prev = step;
        step += (int) sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    while (arr[prev] < target) {
        numberComparisons++;
        prev++;
        if (prev == std::min(step, n)) {
            return -1;
        }
    }
    if (arr[prev] == target) {
        return prev;
    }
    return -1;
}