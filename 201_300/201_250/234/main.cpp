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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr!=nullptr) {
            ListNode* curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }
        return prev;
    }

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

    bool isPalindrome(ListNode* head) {
        ListNode* curr1 = head;
        ListNode* curr2 = reverseLinkedList(middleNode(head));

        while (curr1->next != nullptr) {
            if (curr1->val != curr2->val) {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    }
};

int main() {
    Solution sol;
    return 0;
}

