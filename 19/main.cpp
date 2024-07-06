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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Basically we want to remove the L-n+1 node
        // starting from the front.

        // [*] And you should know that to delete
        // a node at position k, you need to
        // have the node at position k-1 since
        // you need to reconnect the link from node k-1
        // to node k+1.

        // The obvious thing is the node to be deleted
        // is at position n from end, meaning if you have
        // a pointer q that points at the last node
        // and another pointer p n-distance away from q,
        // you know you'll want to delete p.

        // But, recall point [*], to delete p, you need
        // to have p-1. To resolve this without creating
        // another pointer that follows p and because
        // in the end you need to point to head pointer and
        // because what if the list length is 1, we
        // create a fake node in the beginning. This fake
        // node thingy is common trick in linkedlist problems!

        // Thus, if your pointer p starts at this fake node
        // and before traversing you advance q to be n steps
        // ahead, you'll make sure that when q is at the last
        // node, distance between p and q is n+1, which is what you
        // want so you can delete the node after p (i.e: the requested
        // node) and be able to relink.

        ListNode fake(-1, head);
        ListNode *fp = &fake;
        ListNode *lp = &fake;

        // Advance lp n steps
        for (int i=0; i<n; i++) {
            lp = lp->next;
        }

        // Now move them both as usual
        while (lp->next != nullptr) {
            lp = lp->next;
            fp = fp->next;
        }

        // Delete node after fp (in leetcode env. no need to call `delete`)
        fp->next = fp->next->next;
        return fake.next;
    }
};

int main() {
    Solution sol;
    return 0;
}

