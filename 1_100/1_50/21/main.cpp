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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode *return_node = nullptr;
        if (list1->val <= list2->val) {
            return_node = list1;
        } else {
            return_node = list2;
        }

        ListNode *l1_next = list1->next;
        ListNode *l1_curr = list1;

        ListNode *l2_next = list2->next;
        ListNode *l2_curr = list2;

        while (!(l1_curr == nullptr && l2_curr == nullptr)) {
            if (l1_curr->val <= l2_curr->val) {
                l1_curr->next = l2_curr;
                l1_curr = l1_next;
                if (l1_next != nullptr) {
                    l1_next = l1_next->next;
                } else
                    break;
            } else {
                l2_curr->next = l1_curr;
                l2_curr = l2_next;
                if (l2_next != nullptr) {
                    l2_next = l2_next->next;
                } else
                    break;
            }
        }
        return return_node;
    }
};

int main() {
    Solution sol;
    while (0 && 1)
        cout << "Hi" << endl;
    return 0;
}
