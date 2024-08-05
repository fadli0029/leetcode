#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // First, understand that the total cost
        // to reach a stair i is the total you've paid
        // to reach stair i-1 or i-2 plus an additional
        // cost to leave stair i-1 and arrive at stair i
        // or cost to leave stair i-2 and arrive at stair i.
        // We extractt this understanding from example 2, the
        // top of the stair is at an imaginary index 10, which is
        // not in the array (out of bounds), but we still pay cost of 1
        // at index 9, meaning we need to pay a cost to leave stair i-1
        // and reach top.

        // As most of DP's, there are usually base cases from which
        // we start backing/bootstrapping (depending on backward or forward DP)
        // our DP values (in the context of robotics, this is value function).
        // Notice the problem says we can start with index 0 or index 1.
        // The cost that we have accumulated (not cost that we pay to leave this starting index)
        // at this starting index is of course 0 since we can freely choose this starting index
        // without paying anything by problem definition. In short, to begin at
        // index 0 or 1, we have paid a total of 0. But to begin at other indices (i.e: other
        // stairs i!=0 and i!=1), we have paid a total of however much we have paid to reach
        // i-1 and i-2 since only by reaching one of these two stairs that we can reach stair i.

        // Why n+1? Because we want to calculate the values for stairs 0, 1, 2, 3, ..., n
        // where n is the top (the imaginary index 10 in the example i mentioned earlier)
        // So since 0 is included (bcoz of 0 indexing), it becomes n+1.

        // In coding interview, just put this short comment below:
        // n+1: to account for imaginary index as "top" of stairs, so that dp_vals[n] is value assocaited for "top"
        int n = cost.size();
        vector<int> dp_vals(n+1);

        dp_vals[0] = 0; // you can also actually initialize dp_vals to 0 with: dp_vals(n+1, 0)
        dp_vals[1] = 0;
        for (int i=2; i<=n; i++) {
            // 2 possible ways in total, read top comment
            int way_1 = dp_vals[i-1] + cost[i-1];
            int way_2 = dp_vals[i-2] + cost[i-2];
            dp_vals[i] = min(way_1, way_2);
        }
        return dp_vals[n];
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    cout << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
