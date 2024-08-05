#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // idea: for every (p, q) \in matrix, let (p, q)
        // be the top-left corner of the current square
        // of interest. Then, let dp[i, j] be the max
        // area of a square with all 1's whose top left
        // corner is (p, q).
        // This means, dp[m-1][n-1] = 1 if matrix[p][q] = 1, else 0.
        // This is indeed our base case.

        // Now for the recurrence relationship. For every
        // top-left-corner (TLC) candidate, we need to look
        // at its right, below, and its south-east diagonal.
        // This is because the maximum all 1's square area of TLC
        // is the maximum of all 1's square area that its
        // right cell, below, or SE diagonal can make if they were the TLC instead.

        // See: https://youtu.be/6X7Ha2PrDmM?si=-DO3cMfmOfLocUFI for image.

        printMatrix(matrix);
        cout << endl;
        int m = matrix.size();
        int n = matrix[0].size();
        if (m==1) {
            return *max_element(matrix[0].begin(), matrix[0].end()) - '0';
        }

        int curr_max = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = matrix[m-1][n-1] - '0';
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (i==m-1 && j==n-1) { continue; }

                if (i==m-1) {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else if (j==n-1) {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else {
                    bool all_ones = dp[i+1][j+1]*dp[i+1][j]*dp[i][j+1];
                    if (all_ones) {
                        if (dp[i+1][j+1] == dp[i+1][j] == dp[i][j+1]) {
                            dp[i][j] = dp[i+1][j+1] + 1;
                        }
                        else {
                            dp[i][j] = min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
                        }
                    }
                    else {
                        dp[i][j] = matrix[i][j] - '0';
                    }
                }
                curr_max = max(curr_max, dp[i][j]);
            }
        }
        printMatrix(dp);
        return curr_max*curr_max;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    // vector<vector<char>> matrix = {{'0','1'},{'1','0'}};
    // vector<vector<char>> matrix = {{'0'}};
    sol.maximalSquare(matrix);
    return 0;
}

