#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size()-1;
        while (low<=high) {
            int mid = low + (high-low)/2;
            if (int(letters[mid])>int(target)) {
                // maybe there's a letter lexicographically
                // smaller than mid but greater than f
                high = mid - 1;
            }
            else if (int(letters[mid])<=int(target)) {
                // <= instead of < bcoz we want strictly greater (read problem)
                // we have to go right
                low = mid + 1;
            }
        }
        if (low == letters.size()) {
            return letters[0];
        }
        return letters[low];
    }
};

int main() {
    Solution sol;
    return 0;
}

