#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int min_k = high;

        while (low<=high) {
            int mid = low + (high-low)/2;
            long int h_acc = 0;
            for (int i = 0; i < piles.size(); i++) {
                h_acc += ceil((double)piles[i]/mid);
            }
            if (h_acc <= h) {
                // may be best k, but may find lower
                // update k
                min_k = min(min_k, mid);
                high = mid - 1;
            }
            else {
                // need to increase k
                low = mid + 1;
            }
        }
        return min_k;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {3,6,7,11};
    int h = 6;
    cout << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}

