#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* Let L = distance from head to entry point of the ring.
 * Let C = circumference of the ring.
 * Let X = distance from entry point to the encounter point. 
 * then 2 * (L + X) = n * C + L + X
 * L = n * C - X
 * L = (n - 1) * C + (C - X)
 * L == C - X means two nodes start from the head and encounter point (C - X)
 * individually, they would eventually encounter again at the entry point.
 */
static struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {
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

    return NULL;
}

int main(int argc, char **argv)
{
    int i, count = argc - 1;
    struct ListNode *head = NULL, *p, *prev;
    for (i = 0; i < count; i++) {
        p = malloc(sizeof(*p));
        p->val = atoi(argv[i + 1]);
        p->next = NULL;
        if (head == NULL) {
            head = p;
        } else {
            prev->next = p;
        }
        prev = p;
    }
    p->next = head;

    p = detectCycle(head);
    if (p != NULL) {
        printf("%d\n", p->val);
    }
    return 0;
}
