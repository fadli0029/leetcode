#include "bits/stdc++.h"
#include "helpers.cpp"

using namespace std;


class TimeMap {
private:
    map<string, map<int, string>> data;
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        this->data[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (data.find(key) == data.end()) {
            return "";
        }

        const auto& time_map = data[key];
        auto it = time_map.upper_bound(timestamp);
        if (it == time_map.begin()) {
            return ""; // No timestamp <= given timestamp
        }
        --it; // Move iterator to the largest timestamp <= given timestamp
        return it->second;

        // Even this is slow, need to use C++ upper bound.
        // I didn't resolve to that initially bcoz I thought
        // interviews won't allow built-in functions.
        // const auto& time_map = this->data[key];
        // auto it = time_map.begin();
        // auto end = time_map.end();

        // int low = 0;
        // int high = distance(it, end) - 1;

        // while (low<=high) {
        //     int mid = low + (high-low)/2;
        //     auto mid_it = next(it, mid);
        //     if (mid_it->first > timestamp) {
        //         high = mid - 1;
        //     }
        //     else if (mid_it->first < timestamp) {
        //         low = mid + 1;
        //     }
        //     else {
        //         return mid_it -> second;
        //     }
        // }

        // if (low == 0) {
        //     // There is no ts such that t\in time_map <= timestamp
        //     return "";
        // }
        // // Return largest ts such that t\in time_map < timestamp
        // auto res_it = next(it, low-1);
        // return res_it->second;

        // Below is slow, we can directly do binary search on the
        // map using c++ iterators like above.
        // int ts;
        // // binary search on times
        // int low = 0;
        // int high = times.size() - 1;
        // while (low<=high) {
        //     int mid = low + (high - low)/2;
        //     if (times[mid] > timestamp) {
        //         // go left
        //         high = mid - 1;
        //     }
        //     else if (times[mid] < timestamp) {
        //         // go right
        //         low = mid + 1;
        //     }

        //     else {
        //         return this->data[key][times[mid]];
        //     }
        // }
        // if (low == 0) {
        //     // There is no ts such that ts <= timestamp
        //     return "";
        // }
        // else {
        //     // Return largest ts such that ts < timestamp
        //     ts = times[low - 1];
        // }
        // return this->data[key][ts];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    Solution sol;
    return 0;
}

