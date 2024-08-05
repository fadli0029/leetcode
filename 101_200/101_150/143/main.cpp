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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr) {
            if (fast->next->next == nullptr) {
                return slow->next;
            }
            slow = slow->next;
            fast = fast->next->next; // move twice as fast;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
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

    void reorderList(ListNode* head) {
        ListNode* hp = findMid(head); // halfpoint
        ListNode* reversed_hp = reverseList(hp);

        while (head != nullptr) {
            // save the link before breaking
            ListNode* l1 = head->next;
            ListNode* l2 = reversed_hp->next;

            head->next = reversed_hp;
            if (head->next->next == nullptr) {
                break;
            }
            head = l1;

            reversed_hp->next = l1;
            reversed_hp = l2;
        }
    }
};

int main() {
    Solution sol;
    return 0;
}

