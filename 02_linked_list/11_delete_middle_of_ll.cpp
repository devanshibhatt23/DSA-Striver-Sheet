#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    ListNode* middle = head;
    ListNode* prev = head;

    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev->next) {
        prev->next = prev->next->next;
        return head;
    }
    else return NULL;
}