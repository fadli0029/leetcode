#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

// Solved myself but took 50 mins 44 seconds to solve lol.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lp = 0;
        int rp = numbers.size() - 1;

        while (lp < rp) {
            int comp = target - numbers[lp];
            if (comp > numbers[rp] && (rp!=(numbers.size()-1))) {
                rp++;
                if (numbers[rp] > comp) {
                    lp++;
                }
            }
            else if (comp > numbers[rp] && (rp==(numbers.size()-1))) {
                lp++;
            }
            else if (comp < numbers[rp]) {
                rp--;
                if (numbers[rp] < comp) {
                    lp++;
                }
            }
            else {
                return {lp+1, rp+1};
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    return 0;
}

