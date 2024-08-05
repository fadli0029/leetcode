#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        while (fast_ptr->next != nullptr) {
            if (fast_ptr->next->next == nullptr) {
                return slow_ptr->next;
            }
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        return slow_ptr;
    }
};

int main() {
    Solution sol;
    return 0;
}

