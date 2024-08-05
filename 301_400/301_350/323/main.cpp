#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    class DisjointSet {

        public:
            DisjointSet(int size) {
                root.resize(size);
                rank.resize(size);
                for (int i=0; i<size; i++) {
                    root[i] = i;
                    rank[i] = 1;
                }
            }

            int find(int x) {
                if (x == root[x]) {
                    return x;
                }

                return root[x] = find(root[x]);
            }

            void merge(int x, int y) {
                int root_x = root[x];
                int root_y = root[y];
                if (root_x != root_y) {
                    if (rank[root_x] > rank[root_y]) {
                        root[root_y] = root_x;
                    }
                    else if (rank[root_x] < rank[root_y]) {
                        root[root_x] = root_y;
                    }
                    else {
                        root[root_y] = root_x;
                        rank[root_x]++;
                    }
                }
            }

            bool connected(int x, int y) {
                return find(x) == find(y);
            }

        private:
            vector<int> root;
            vector<int> rank;
    };

    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int n_cc = n;
        for (const auto& e : edges) {
            if (!ds.connected(e.at(0), e.at(1))) {
                n_cc--;
                ds.merge(e.at(0), e.at(1));
            }
        }
        return n_cc;
    }
};

int main() {
    Solution sol;
    return 0;
}

