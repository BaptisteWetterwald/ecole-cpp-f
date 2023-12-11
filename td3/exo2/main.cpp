//
// Created by Baptiste WETTERWALD on 11/12/2023.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target){
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size() ; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int remaining = target - nums[i];
        if (map.find(remaining) != map.end()) {
            return {map[remaining], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "BruteForce Solution: ["
        << indicesBruteForce[0]
        << ", "
        << indicesBruteForce[1]
        << "]"
        << endl;

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: ["
        << indicesOptimal[0]
        << ", "
        << indicesOptimal[1]
        << "]"
        << endl;

    return 0;
}
