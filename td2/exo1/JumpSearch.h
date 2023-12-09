//
// Created by Baptiste  WETTERWALD on 16/11/2023.
//

#ifndef ECOLE_CPP_F_JUMPSEARCH_H
#define ECOLE_CPP_F_JUMPSEARCH_H


#include "SearchingAlgorithm.h"

class JumpSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int> &arr, int target) override;
};


#endif //ECOLE_CPP_F_JUMPSEARCH_H
