#include "bits/stdc++.h"
#include "helpers.cpp"
#include <iostream>
using namespace std;

class Solution {
  public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            int res = 0;
            for (const char& x : to_string(n)) {
                res += pow(x - '0', 2);
            }
            n = res;
        }
        return n == 1;
    }
};

int main() {
    int n = 2;
    Solution sol;
    cout << "Output: " << sol.isHappy(n) << endl;
    return 0;
}
