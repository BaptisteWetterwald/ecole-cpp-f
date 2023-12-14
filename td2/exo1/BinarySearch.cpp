//
// Created by Baptiste WETTERWALD on 16/11/2023.
//

#include "BinarySearch.h"
#include <vector>

int BinarySearch::search(const std::vector<int> &arr, int target) {
    //return search_it(arr, target);
    return search_rec(arr, target, 0, (int) arr.size() - 1);
}

int BinarySearch::search_it(const std::vector<int> &arr, int target) {
    totalSearch++;
    numberComparisons = 0;
    int left = 0;
    int right = (int) arr.size() - 1;
    while (left <= right) {
        numberComparisons++;
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int BinarySearch::search_rec(const std::vector<int> &arr, int target, int left, int right) {
    totalSearch++;
    numberComparisons++;
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] < target) {
        return search_rec(arr, target, mid + 1, right);
    }
    return search_rec(arr, target, left, mid - 1);
}