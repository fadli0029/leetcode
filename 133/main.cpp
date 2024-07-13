#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    std::unordered_map<Node*, Node*> visited;

public:
    // This code is written to closely reflect the understanding
    // from this video: https://youtu.be/8qs4XEwIWSY?si=c9c7u9Bqimb_tzL3
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        std::stack<Node*> stack;
        stack.push(node);
        while (!stack.empty()) {
            Node* curr = stack.top();
            stack.pop();

            // If the current node has not been visited yet, clone it
            if (!visited.contains(curr)) {
                Node* curr_clone = new Node(curr->val, {});
                visited[curr] = curr_clone;
            }

            // Iterate through the neighbors of the current node
            for (Node* nbr : curr->neighbors) {
                if (!visited.contains(nbr)) {
                    Node* nbr_clone = new Node(nbr->val, {});
                    visited[nbr] = nbr_clone;

                    stack.push(nbr);
                }
                // Since this is the neighbor of current, update it then.
                // We do this by pushing the cloned neighbor of current
                // to its vector of neighbors.
                visited[curr]->neighbors.push_back(visited[nbr]);
            }
        }

        return visited[node];
    }
};

int main() {
    Solution sol;
    return 0;
}

