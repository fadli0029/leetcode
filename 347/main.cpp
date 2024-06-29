#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

// Naive approach
// class Solution {
// public:
//     static bool sortMap(const pair<int, int>& a, const pair<int, int>& b) {
//         return a.second > b.second;
//     }

//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         if (nums.size() == 1) {
//             return {nums[0]};
//         }
//         else {
//             map<int, int> data;
//             for (const auto& num : nums) {
//                 if (data.find(num) != data.end()) {
//                     data[num]++;
//                 }
//                 else {
//                     data.insert(make_pair(num, 1));
//                 }
//             }
//             vector<pair<int, int>> sorted_map_by_value(data.begin(), data.end());
//             sort(sorted_map_by_value.begin(), sorted_map_by_value.end(), Solution::sortMap);

//             vector<int> res;
//             for (int i=0; i<k; i++) {
//                 res.push_back(sorted_map_by_value[i].first);
//             }
//             return res;
//         }
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return {nums[0]};
        }
        else {
            // store each num and their associated freq.
            unordered_map<int, int> data;
            for (const auto& num : nums) {
              if (data.find(num) != data.end()) {
                  data[num]++;
              }
              else {
                  data.insert(make_pair(num, 1));
              }
            }

            // Bucket sort but with the thing being
            // sorted is the frequency. Meaning,
            // every bucket represents a frequency f and
            // the content in that bucket is all the num \in nums
            // having the frequency f.
            vector<vector<int>> buckets(nums.size());
            for (const auto& kv : data) {
                buckets[kv.second-1].push_back(kv.first);
            }

            // We should iterate the buckets from end to start
            // since we want top k elements (i.e.: descending
            // order of frequency):
            vector<int> res;
            for (int i=nums.size()-1; i>=0; i--) {
                if (res.size() >= k) {
                    break;
                }
                if(!buckets[i].empty()) {
                    res.insert(res.begin(), buckets[i].begin(), buckets[i].end());
                }
            }
            return res;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = sol.topKFrequent(nums, k);
    printVector(res);
    return 0;
}

