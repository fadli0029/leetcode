#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;

        int lp = 0;
        int rp = 1;
        while (rp<prices.size()) {
            if (prices[lp]>prices[rp]) {
                lp++;
            }
            else if (prices[lp]<prices[rp]) {
                max_profit = max(max_profit, prices[rp]-prices[lp]);
                rp++;
            }
            else {
                rp++;
            }
        }
        return max_profit;
    }
};

int main() {
    Solution sol;
    return 0;
}

