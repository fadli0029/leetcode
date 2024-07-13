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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        std::stack<Node*> stack;
        stack.push(node);
        while (!stack.empty()) {
            Node* current = stack.top();
            stack.pop();

            // If the current node has not been visited yet, clone it
            if (!visited.contains(current)) {
                visited[current] = new Node(current->val, {});
            }

            // Iterate through the neighbors of the current node
            for (Node* neighbor : current->neighbors) {
                if (!visited.contains(neighbor)) {
                    // Clone the neighbor and add it to the visited map
                    visited[neighbor] = new Node(neighbor->val, {});
                    // Push the neighbor to the stack for further processing
                    stack.push(neighbor);
                }
                // Add the clone of the neighbor to the neighbors of the clone node
                visited[current]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};

int main() {
    Solution sol;
    return 0;
}

