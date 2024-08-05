#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // `amount + 1` for size bcoz we start from 0 up to amount.
        // `amount + 1` for initialization bcoz suppose
        // you are given `amount` equal to some value K, then in the
        // worst case, your `coins` array is just the coint with value
        // 1. So the number of coins to make that K is literally
        // K itself.
        // But why + 1? Bcoz we want to mark all states initially
        // to be impossible, i.e.: you can't make such and
        // such amount with any number of coins. Technically,
        // you can initialized dp with inifinity, 100000, whatever
        // to capture the notion of all states is not reachable.
        vector<int> dp(amount+1, amount+1);

        // Def'n: Let `dp[i]` be the number of coins needed
        //        to make the amount `i`.
        //        By initialization, dp[i] = infinity if we cannot
        //        make the amount `i` using any combinations
        //        of coin in `coins`.

        // If we're at state `i=0` where `i` = `amount`, we
        // don't need any coins to make `amount` since you
        // need nothing to make nothing.
        dp[0] = 0;
        for (int i=1; i<=amount; i++) {
            // Here, the +1 is bcoz for every transition
            // to a valid state (i.e.: valid amount `i`, where
            // valid here means it is possible to make `i`
            // from coin \in coins), you must have used
            // exactly 1 coin. For example, if i=1
            // and coins = [1,5,11], target doesn't matter for now,
            // to go from i=0 to i=1, you pick coin = 1 from coins.
            // So, one coin has been used. If i = 6, you need
            // to use one coin, whatever that may be, to make this
            // amount plus whatever the number of coins
            // needed to make the amount leading up to 6. If you
            // still don't understand how we come up with this
            // transition equation (a.k.a recursive formula),
            // just use the transition from amount 0 to 1 example.
            // How were we able to transition to 1? I don't care what
            // value the coin is (well it better be 1 LOL), but I know
            // for an actual fact that you must have used 1 coin to get to 1.
            // Let's generalize this, to transition from state
            // x_{i-1} to x_{i}, i.e.: to leave the previous state and
            // go to the next one, it is a fact that one coin is used, regardless
            // of its value. So, the total number of coins used to get to x_{i}
            // is 1 + however many the number of coins it takes to get to
            // x_{i-1}. You see, with DP problems, especially the "how many ways.." variants,
            // to go to the current state x_i, DP problems do not care how you
            // got to the previous state previous states x_{i-1}. All it knows is you need
            // to get to the previous states x_{i-1} first, then leave these states to get
            // to x_i. As long as you have the previous values x_{i-1} by building up
            // from the base case, you can get to the final state.

            // This should remind you of MDP, markov decision process! Bcoz the markov assumption
            // says that only the immediate previous state matters.

            // Okay now back to the question, so we know that the number of
            // coins it takes to make the amount i, i.e.: dp[i] is 1 plus
            // however many it takes to make the previous valid amount:
            // dp[i] = f(i) = 1 + dp[i-coin]
            // The "i-coin" here insted of i-1 bcoz it's not a guarantee
            // that from amount 0 to 11 for example, you can make every
            // amount in there bcoz we are only given coins of certain value.
            // Mathematically, let i be the current amount of interest,
            // k be the previous valid amount and coin \in coins. Then:
            // i = k + coin, \forall coin \in coins.
            // Thus: k = i-coin.

            // Now, we need to add min since we initialized the arrays
            // with infinity, this is just essentially updating the values:
            // if we found better value, update it.

            for (const auto& coin : coins) {
                if (i-coin >= 0) {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount] == (amount+1)? -1 : dp[amount];
    }
};

int main() {
    Solution sol;
    return 0;
}

