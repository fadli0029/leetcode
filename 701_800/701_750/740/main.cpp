#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
        // I couldn't solve this problem under 30 mins.
        // Very good explanation of this problem: https://youtu.be/VHeYZrIDveY?si=pyazaG9rCoPn0OKt

        // You can actually solve this like the house robbing problem.
        // How? The idea is, if you decide to take nums[i], you can't take
        // any number equals to nums[i]+1 and any number equals to nums[i]-1.
        // So if we have the example: [2,2,3,3,3,4], if we take 2, we can't take
        // 3, if we take 3, we can't take 2 or 4, etc.
        // Before we can see the connection to the house robber problem, notice
        // one thing:
        //    If I decide to take a nums[i] = x, whatever that may be,
        //    and there are many such x's (for example in the earlier example
        //    there are two 2's), then might as well take all of them.
        //    Why? Because you have nothing to lose. If you ever decide to take
        //    3 for example, you're gonna delete all occurences of 2 and 4 anyways,
        //    so why just take one 3, when you can take more?
        // Okay, so what? What does this insight tells us? Well, taking nums[i]
        // doesn't just give you nums[i] points. It gives you k*nums[i] points,
        // where k is the occurences of nums[i] in nums. If k=1, surely it just gives
        // you nums[i] as the problem describes.

        // So really, that earlier example, nums = [2,2,3,3,3,4], can be reformated
        // to [4, 9, 4]. Now, remember earlier we said if we take nums[i], we can't take
        // nums[i] - 1 and nums[i] + 1? If you look at the example nums = [2,2,3,3,3,4],
        // doesn't this just means if we decide to take nums[i] we can't take the items
        // adjacent to it? Since we can't represent
        // duplicates as k*nums[i], where k is how many duplicates, then:
        // [2,2,3,3,3,4] = [2, 2 | 3, 3, 3 | 4] = [4, 9, 4]
        // This "we cannot take items adjacent to it" is a giveaway to the house robber problem
        // where it says if we decide to rob a house, we can rob the houses adjacent it.

        // Now, you might ask, what if there is no number that is one greater or one smaller
        // than i? Will this one-one-mapping from this problem to the house robber problem works? Yes.
        // Take `nums = [2,5,8]` for example, you can still treat this as the house robber
        // problem because if you take 2

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) {
            return nums[0];

        }

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i=2; i<n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        if (n==1) {
            return nums[0];
        }

        map<int, int> num_freq;
        for (const auto& num : nums) {
            if (num_freq.find(num) == num_freq.end()) {
                num_freq[num] = 1;
            }
            else {
                num_freq[num]++;
            }
        }
        printMap(num_freq);

        // Create new array
        vector<int> nums_new;
        for (const auto& kv : num_freq) {
            nums_new.push_back(kv.second);
        }
        printVector(nums_new);

        return rob(nums_new);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,4,2};
    cout << sol.deleteAndEarn(nums) << endl;
    return 0;
}

