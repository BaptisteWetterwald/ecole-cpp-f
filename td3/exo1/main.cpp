//
// Created by Baptiste WETTERWALD on 11/12/2023.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countFrequencyBruteForce(const vector<int> &numbers) {
    bool shouldSkip;
    for (int i = 0; i < numbers.size(); i++) {
        shouldSkip = false;
        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                shouldSkip = true;
                break;
            }
        }
        if (shouldSkip) continue;
        int count = 1;
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] == numbers[j]) {
                count++;
            }
        }
        cout << numbers[i] << " : " << count << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int> &arr) {
    map<int, int> frequencies;
    for (int i : arr) {
        if (frequencies.find(i) == frequencies.end()) {
            frequencies[i] = 1;
        } else {
            frequencies[i]++;
        }
    }
    return frequencies;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};
    cout << "Frequency (Brute Force) : " << endl;
    countFrequencyBruteForce(numbers);

    cout << endl << "Frequency (Optimal) : " << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << " : " << entry.second << endl;
    }

    return 0;
}