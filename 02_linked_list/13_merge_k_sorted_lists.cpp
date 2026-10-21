#include <bits/stdc++.h>
#include <queue>
using namespace std;

// n -> total nodes, k -> total lists
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TC - O(n*k), SC - O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode new_head;
        ListNode* temp = &new_head;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 && temp2) {
            if(temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else {
                temp->next = temp2;
                temp2 = temp2->next;
            }

            temp = temp->next;
        }

        if(temp1) {
            temp->next = temp1;
        }
        if(temp2) {
            temp->next = temp2;
        }

        return new_head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        
        for(int i=0; i<n-1; i++) {
            lists[i+1] = mergeTwoLists(lists[i], lists[i+1]);
        }

        return lists[n-1];
    }
};

// TC - O(n log n), SC - O(n)
class Solution {
public:
    struct comparator {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> minHeap;

        for(auto head : lists) {
            ListNode* temp = head;

            while(temp) {
                minHeap.push(temp);
                temp = temp->next;
            }
        }

        ListNode head;
        ListNode* temp = &head;

        while(!minHeap.empty()) {
            temp->next = minHeap.top();
            minHeap.pop();
            temp = temp->next;
        }

        temp->next = NULL;

        return head.next;
    }
};

// TC - O(n log k), SC - O(k)
class Solution {
public:
    struct comparator {
        bool operator()(const ListNode* a, const ListNode* b) const {
            if(a == NULL || b == NULL) return 1;
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;

        ListNode head;
        ListNode* temp = &head;

        priority_queue<ListNode*, vector<ListNode*>, comparator> minHeap;

        for(auto head : lists) {
            if(head) minHeap.push(head);
        }

        while(!minHeap.empty()) {
            ListNode* minimum = minHeap.top();
            minHeap.pop();

            temp->next = minimum;

            if(minimum) {
                minimum = minimum->next;
                minHeap.push(minimum);
                temp = temp->next;
            }
        }

        temp->next = NULL;
        return head.next;
    }
};