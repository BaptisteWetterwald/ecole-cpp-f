//
// Created by Baptiste  WETTERWALD on 16/11/2023.
//

#include "SearchingAlgorithm.h"

SearchingAlgorithm::SearchingAlgorithm() {
    numberComparisons = 0;
}

int SearchingAlgorithm::totalSearch = 0;
int SearchingAlgorithm::totalComparisons = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

void SearchingAlgorithm::displaySearchResults(std::ostream &os, int result, int target) const {
    os << "Target: " << target << (result == -1 ? " not found." : " found at index " + std::to_string(result))
       << std::endl;
    os << "Number of comparisons: " << numberComparisons << std::endl;
}

// Created by Baptiste  WETTERWALD on 16/11/2023.