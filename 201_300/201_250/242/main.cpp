#include "bits/stdc++.h"
#include "helpers.cpp"
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> count(26, 0);
        for (int i = 0; i < s.size(); i++) {
            count[int(s[i]) - int('a')]++;
            count[int(t[i]) - int('a')]--;
        }
        return all_of(count.begin(), count.end(), [](int i) { return i == 0; });
    }
};

int main() {
    Solution sol;
    return 0;
}
