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
                if (root_x!=root_y) {
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

    class Edge {
        public:
            Edge(int p1, int p2, int cost) :
                p1(p1), p2(p2), cost(cost) {
                }

            bool operator<(const Edge& other) const {
                return this->cost>other.cost;
            }

            int p1, p2, cost;
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        // We can use Kruskal's algo.

        // 1. Sort & create the edges.
        // First step is to sort the edges in ascending order.
        // of their cost. Since there are no edges pre-defined,
        // we create them according to the problem's definition.

        // C++ priority queue is descending order by default
        // but we overloaded the > operator for Edge to mean <
        // instead, so this issue is handled.
        priority_queue<Edge> pq;
        for (int i=0; i<points.size(); i++) {
            for (int j=i+1; j<points.size(); j++) {
                vector<int> coord1 = points[i], coord2 = points[j];
                int cost = abs(coord1[0] - coord2[0]) +
                           abs(coord1[1] - coord2[1]);
                Edge e(i, j, cost);
                pq.push(e);
            }
        }

        // 2. Try to add edges
        // We use DisjointSet data structure to make sure
        // no edge added will introduce a cycle, by definition
        // this means we will not add an edge between i and j
        // if they are already in the same component.
        int n = points.size();
        int res = 0;
        int edges_added = 0;
        DisjointSet ds(n);
        while(!pq.empty() && edges_added!=n-1) {
            Edge curr = pq.top();
            pq.pop();
            if (!ds.connected(curr.p1, curr.p2)) {
                ds.merge(curr.p1, curr.p2);
                res += curr.cost;
                edges_added++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}

