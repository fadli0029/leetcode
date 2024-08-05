#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned int lp = 0;
        unsigned int rp = 0;

        set<char> substr;
        unsigned int length = 0;
        while (rp < s.size()) {
            while (substr.contains(s[rp])) {
                substr.erase(s[lp]);
                lp++;
            }
            substr.insert(s[rp]);
            length = max(length, rp-lp+1);
            rp++;
        }
        return length;
    }
};

int main() {
    Solution sol;
    int i = 0;
    int j = 1;
    while (i < 11) {
        j++;
        cout << j << endl;
        break;
    }
    return 0;
}

