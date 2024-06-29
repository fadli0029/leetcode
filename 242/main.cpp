#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        else {
            // in the end every letters count must be 0
            // iff for every occurence of a letter in s we increment
            // its count and for that same letter in t we decrement
            // its count in the vector.
            vector<int> all_zeros(26, 0);
            vector<int> count(26, 0); // count[0] is freq. of a, count[1] is freq. of b, etc.
            for (size_t i=0; i<s.size(); i++) {
                // compute the index
                size_t s_curr_ch_index = int(s[i]) - int('a');
                size_t t_curr_ch_index = int(t[i]) - int('a');
                // update their count
                count[s_curr_ch_index]++;
                count[t_curr_ch_index]--;
            }
            return (count == all_zeros);
        }
    }
};

int main() {
    Solution sol;
    string s = "cat";
    string t = "rat";
    cout << sol.isAnagram(s, t) << endl;
    return 0;
}

