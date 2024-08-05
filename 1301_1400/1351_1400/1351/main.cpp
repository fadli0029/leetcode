#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int row = 0; row<m; row++) {
            int low  = 0;
            int high = n-1;
            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (grid[row][mid]>=0) {
                    // move right
                    low = mid + 1;
                }
                else {
                    // T found, but there could be a
                    // T to the left too, so keep looking.
                    // Basically we want to find first T.
                    // (if you have no idea what this means,
                    //  read your blog on how to solve
                    //  binary search problems by putting T and F)
                    high = mid - 1;
                }
            }
            if (low == n) {
                // reached end, T was never found
                ;
            }
            else {
                // low > high
                count = count + (n - low);
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    return 0;
}

