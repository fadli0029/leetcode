#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int max_profit = 0;

        int lp = 0;
        int rp = 1;
        while (rp < prices.size()) {
            int curr_profit = prices[rp] - prices[lp];
            if (curr_profit >= 0) {
                rp++;
            } else {
                lp = rp;
                rp++;
            }
            max_profit = max(max_profit, curr_profit);
        }
        return max_profit;
    }
};

int main() {
    Solution sol;
    return 0;
}
