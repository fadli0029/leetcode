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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode imag(-1);
        ListNode* tracker = &imag;
        while (list1!=nullptr && list2!=nullptr) {
            if (list1->val <= list2->val) {
                tracker->next = list1;
                list1 = list1->next;
            }
            else {
                tracker->next = list2;
                list2 = list2->next;
            }
            tracker = tracker->next;
        }
        tracker->next = list1 == nullptr ? list2 : list1;
        return imag.next;
    }
};

int main() {
    Solution sol;
    return 0;
}

