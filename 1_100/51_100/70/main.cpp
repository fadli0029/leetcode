#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

// Note to self:
// When you visit other DP problems you have solved
// or have not solved, I want you to remember what makes
// DP challenging is the following: figuring out if a problem
// can be solved by DP. Once you know that you can solved the problem
// by DP, you pretty much have solved it.

// The challenges of figuring out if a problem can be solved by DP are 3:
// 1. Figuring out what are the subproblems that will lead to solving the main problem. Do they even exist?
// 2. Figuring out the base cases. Are they base case?
// 3. Figuring out the recursive formula for a general solution, i.e: the formula that takes the form
//    of a bellman equation: V[i] = ... +/-* ... V[i+- something] (you see your dp table, denoted V here, on both sides
//    of the equation). So, if you realize the problem can be formulated this way, then DP will solve
//    the problem. Fibonacci is a good example of this.
class Solution {
public:
    int climbStairs(int n) {
        // for any staircase i, there are only
        // two ways that could possibly lead us to it.
        // 1. Two steps were taken to reach it.
        // 2. One steps were taken to reach it.

        // This means, for any staircase i, the number
        // of ways to reach it is the number of ways
        // to reach the staircase i-2 plus the number of
        // ways to reach the staircase i-1. This is because
        // only by reaching staircase i-2 or i-1 you can
        // possibly reach staircase i since there are only
        // two ways to reach staircase i as mentioned earlier.
        // If you're at staircase i-3, you can't get to staircase
        // bcoz that would require 3 steps.

        // The base case is for i = 1 and i = 1. The number
        // of steps to go to staircase 0 is 1 and the number of
        // steps it takes to go to staircase 1 is 1. Think of
        // staircase 0 as a virtual/imaginary staircase. I mean it
        // makes sense to, you can go to staircase 1 without first
        // being very close to it, and to be very close to it
        // you need to take some steps to get there. Since these
        // "some steps" is not defined, it's safe to assume it's 1. Why
        // is it safe? Because take simple values of n with n = 1, n
        // n = 2, n = 3. Using the formula earlier, the number come out
        // will be correct.

        // If all the virtual staircase thing doesn't make sense, there's
        // a different approach that uses backward DP: https://youtu.be/Y0lT9Fck7qI?si=bGQiXLJlgDWoHWIH

        // What we're doing is forward DP, i.e.: travelling forward in time.

        vector<int> ways(n+1); // n+1 to account for the virtual/imaginary staircase
        ways[0] = 1;
        ways[1] = 1;
        for (int i=2; i<n; i++) {
            ways[i] = ways[i-1] + ways[i-2];
        }
        return ways[n];
    }
};

int main() {
    Solution sol;
    return 0;
}

