#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i<j) {
            // ---------------------------
            // Skip non-alphanumeric chars
            while (!isalnum(s[i]) && i<j) {
                i++;
            }
            while (!isalnum(s[j]) && i<j) {
                j--;
            }
            // ---------------------------

            if (tolower(s[i])!=tolower(s[j])) {
                return false;
            }
            else {
                // Characters are equal at both pointers, advance.
                i++;
                j--;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}

