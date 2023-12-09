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

/*std::ostream & operator<<(std::ostream &os, const SearchingAlgorithm &) {
    os << "Total searches: " << SearchingAlgorithm::totalSearch << std::endl;
    os << "Total comparisons across all searches: " << SearchingAlgorithm::totalComparisons << std::endl;
    os << "Average comparisons per search: " << SearchingAlgorithm::averageComparisons << std::endl;
    return os;
}*/

/*void SearchingAlgorithm::displaySearchResults(std::ostream& os, int result, int target) {
    os << "Target: " << target << (result == -1 ? " not found." : " found at index " + std::to_string(result)) << std::endl;
    os << "Number of comparisons: " << numberComparisons << std::endl;
    totalSearch++;
    totalComparisons += numberComparisons;
    averageComparisons = (double) totalComparisons / totalSearch;
    numberComparisons = 0;
}*/

void SearchingAlgorithm::displaySearchResults(std::ostream &os, int result, int target) const {
    os << "Target: " << target << (result == -1 ? " not found." : " found at index " + std::to_string(result)) << std::endl;
    os << "Number of comparisons: " << numberComparisons << std::endl;
}

// Created by Baptiste  WETTERWALD on 16/11/2023.