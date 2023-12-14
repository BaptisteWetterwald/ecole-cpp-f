//
// Created by Baptiste  WETTERWALD on 16/11/2023.
//

#ifndef ECOLE_CPP_F_BINARYSEARCH_H
#define ECOLE_CPP_F_BINARYSEARCH_H

#include "SearchingAlgorithm.h"

class BinarySearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int> &arr, int target) override;

    int search_it(const std::vector<int> &arr, int target);

    int search_rec(const std::vector<int> &arr, int target, int left, int right);
};

#endif //ECOLE_CPP_F_BINARYSEARCH_H
