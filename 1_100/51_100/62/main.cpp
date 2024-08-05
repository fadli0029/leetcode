#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Make sure you have solved Leetcode #70
        // and Leetcode #746 so this pattern makes sense to you.

        // ----------------------------------------------------------------------------------
        // BEFORE YOU KEEP READING:
        // I just want you to engrave in your mind that DP,
        // Dynamic Programming, is all about identifying subproblems.
        // If you can break down a problem into subproblems, there's a high chance
        // you can apply DP to solve it. After all, DP involves solving these subproblems and
        // caching their solutions, which are then used to solve larger subproblems,
        // eventually building up to the solution of the main problem.
        // ----------------------------------------------------------------------------------

        // First, given the problem definition
        // the only way to reach cell (i, j), where
        // i is the i'th row and j is the j'th column,
        // is if we came from (i-1, j), i.e.: we went
        // down, or we came from (i, j-1), i.e.: we
        // went right. Now we have a formula for our
        // dp_vals! (you should recall the pattern of
        // dp problem is always recognizing a formula
        // for our dp_vals.

        // Next, if you recall the pattern again, we need
        // to identify the base case. In this problem,
        // since we're trying to find the numnber of ways to get to
        // a cell, the base case should be the answer to the
        // question: "Is there a cell where we know exactly
        // how many ways to get to that cell?".
        // After all, we have:
        // dp_vals[i][j] = dp_vals[i-1][j] + dp_vals[i][j-1]
        // (where dp_vals[i][j] here is the number of unique
        // paths/ways to get to cell (i, j))
        // but where do we get dp_vals[i-1][j] + dp_vals[i][j-1]
        // to begin with?
        // To answer this question, always you need to ask:
        //      What do we know from the problem?
        // Well, we are told in the problem the robot starts at
        // cell (0, 0). How many ways to reach this starting
        // cell, i.e.: what is dp_vals[0][0]? Well of course
        // it's 1 bcoz we begin at that cell, there's not
        // really any ways of choosing where to start besides
        // the way given by the problem, which is one way.

        // There's one last catch. For every DP problem, once you
        // come up with a formula, always ask, will this be valid
        // for all i/j or there are edge cases? In our case, yes!
        // Look at i=0, i.e.: first row, any of the cells in the
        // first row, there's only one way to reach them: by going right from (0, 0)
        // So, for these cells dp_vals[i][j] = dp_vals[i][j-1].
        // The same goes for the cells in the first column, there's only
        // one way to reach them: by going down from (0,0).
        // So, for these cells dp_vals[i][j] = dp_vals[i-1][j].
        // Okay, how do you elegantly handle these edges cases? If statements?
        // Sure, but there's an elegant way to do it:
        // Pad the top of our grid with a row of all zeros and the left
        // of our grid with column of all zeros.
        // The result of this is our starting cell is really: padded_grid[1][1]
        // And now we can do dp without changing the formula.

        // m+1 and n+1 for padding
        vector<vector<int>> dp_vals(m+1, vector<int>(n+1, 0));
        dp_vals[1][1] = 1;
        for (int i=1; i<=m; i++) {
          for (int j=1; j<=n; j++) {
              if (i == 1 and j == 1) {continue;} // because this is the base case
              dp_vals[i][j] = dp_vals[i-1][j] + dp_vals[i][j-1];
          }
        }
        return dp_vals[m][n];
    }
};

int main() {
    Solution sol;
    return 0;
}

