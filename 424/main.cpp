#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> char_freqs(26, 0);
        int max_count = 0;

        int lp = 0, rp = 0, curr_best = 0;

        while (rp < s.size()) {
            char_freqs[s[rp] - int('A')]++;
            max_count = max(max_count, char_freqs[s[rp] - int('A')]);
            int len = rp-lp+1 - max_count;
            if (len > k) {
                char_freqs[s[lp] - int('A')]--;
                lp++;
            }
            curr_best = max(rp-lp+1, curr_best);
            rp++;
        }
        return curr_best;
    }
};

int main() {
    Solution sol;
    return 0;
}

