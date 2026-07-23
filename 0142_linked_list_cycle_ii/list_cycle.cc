#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
// Let L = distance from head to the entry point of the ring.
// Let C = circumference of the ring.
// Let X = distance from entry point to the encounter point. 
// then 2 * (L + X) = n * C + L + X
// L = n * C - X
// L = (n - 1) * C + (C - X)
// L == C - X means two nodes start from the head and encounter point (C - X)
// individually, they would eventually encounter again at the entry point.
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
