#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
  public:
    vector<vector<int>> generate_neighbors(const int &M, const int &N,
                                           const int &i, const int &j) {
        vector<vector<int>> nbrs;
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int k = 0; k < 8; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < M && nj >= 0 && nj < N) {
                nbrs.push_back({ni, nj});
            }
        }
        return nbrs;
    }

    int count_adj_mines(const vector<vector<char>> &board,
                        const vector<vector<int>> &nbrs_ij, const int &i,
                        const int &j) {
        int adj_mines = 0;
        for (const auto nbr : nbrs_ij) {
            int i_nbr = nbr[0], j_nbr = nbr[1];
            if (board[i_nbr][j_nbr] == 'M')
                adj_mines++;
        }
        return adj_mines;
    }

    void reveal(vector<vector<char>> &board, const int &i, const int &j) {
        int M = board.size(), N = board[0].size();
        vector<vector<int>> nbrs_ij = generate_neighbors(M, N, i, j);

        if (board[i][j] == 'E') {
            int adj_mines = count_adj_mines(board, nbrs_ij, i, j);
            if (adj_mines) {
                board[i][j] = '0' + adj_mines; // int->char conversion
            } else {
                board[i][j] = 'B';
                for (const auto nbr : nbrs_ij) {
                    int i_nbr = nbr[0], j_nbr = nbr[1];
                    reveal(board, i_nbr, j_nbr);
                }
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                     vector<int> &click) {
        int i = click[0], j = click[1];
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return board;
        }
        reveal(board, i, j);
        return board;
    }
};

int main() {
    Solution sol;
    return 0;
}
