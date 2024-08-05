// TODO: solve this with ece276b DP knowledge
#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    using Matrix = std::vector<std::vector<int>>;

    int runPolicy(const vector<int>& P, const vector<int>& cost, const int& N) {
        // start: starting state, can either be x=0 or x=1
        // Policy
        // cost at each state x

        int start_0 = 0;
        int curr_cost_1 = cost[start_0];
        for (int x=start_0; x<P.size(); x++) {
            int next_state = stateTransition(x, P[x], N);
            curr_cost_1 += cost[next_state];
        }

        int start_1 = 1;
        int curr_cost_2 = cost[start_1];
        for (int x=start_1; x<P.size(); x++) {
            int next_state = stateTransition(x, P[x], N);
            curr_cost_2 += cost[next_state];
        }

        return std::min(curr_cost_1, curr_cost_2);
    }

    int stateTransition(int x, int u, int N) {
        // if x+u > N-1, then we have reach the goal
        // and we should return N because we define goal state to be x.
        // if x+u < 0, then we are out of bound
        // and we should return 0
        if (x+u > N-1) {
            return N;
        } else if (x+u < 0) {
            return 0;
        } else {
            return x+u;
        }
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // We can frame this like robotics problem,
        // in particular the FHOC, Finite Horizon
        // Optimal Control problem where we want
        // to determine the optimal control (in this case
        // steps to take) to reach the goal (in this case
        // top of stairs) in such a way that minimize the
        // cost to be paid. In this case, we can think
        // of the array cost as the stage cost l(x, u)
        // i.e.: the cost to be paid at state x after taking action u,
        // and this is constant on u. Which means the Q-value compuation
        // in the DP algorithm only needs us to iterate over x.

        // Now let's define the problem:
        // the terminal state is an added imaginary state, N
        // The value function at terminal state is q(x) = 0;

        int N = cost.size(); // no. of states
        int M = 2;

        Matrix V_t(N, std::vector<int>(N, 0)); // at worst, we take one step each so time horizon is N
        for (int x=0; x<N; x++) {
            V_t[N-1][x] = 0;
        }
        Matrix P_t(N, std::vector<int>(N, 0));
        for (int t=N-1; t>=0; t--) {
            Matrix Q_t(N, std::vector<int>(M, 0));
            for (int x=0; x<N+2; x++) {
                for (int u=1; u<3; u++) {
                    Q_t[x][u-1] = cost[x] + V_t[stateTransition(x, u, N)];
                }
            }
            cout << "Q_t at time t" << endl;
            printMatrix(Q_t);
            cout << endl;
            for (int x=0; x<N+2; x++) {
                V_t[x] = *std::min_element(Q_t[x].begin(), Q_t[x].end());
            }
            // find argmin over u of Q_t(x, u)
            for (int x=0; x<N; x++) {
                P_t[x] = std::min_element(Q_t[x].begin(), Q_t[x].end()) - Q_t[x].begin() + 1;
            }
        }
        printVector(V_t);
        printVector(P_t);
        return runPolicy(P_t, cost, N);
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    cout << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
