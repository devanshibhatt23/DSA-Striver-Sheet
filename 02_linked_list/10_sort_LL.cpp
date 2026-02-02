#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int data1, Node* next1) {
        val = data1;
        next = next1;
    }

    Node(int data1) {
        val = data1;
        next = nullptr;
    }
};

Node* middle(Node* head) {
    if(head == NULL) return head;
    
    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* left, Node* right) {
    Node dummy(-1);
    Node* new_head = &dummy;

    while(left && right) {
        if(left->val <= right->val) {
            new_head->next = left;
            left = left->next;
        }
        else {
            new_head->next = right;
            right = right->next;
        }
        new_head = new_head->next;
    }

    if(left) new_head->next = left;
    if(right) new_head->next = right;

    return dummy.next;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* mid = middle(head);
    Node* left_head = head;
    Node* right_head = mid->next;

    mid->next = NULL;
    left_head = mergeSort(left_head);
    right_head = mergeSort(right_head);
    
    return merge(left_head, right_head);
}

Node* convertArrToLL(vector<int> &v) {
    Node* head = new Node(v[0]);
    Node* mover = head;

    for(int i=1; i<v.size(); i++) {
        Node* temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

Node* sortList(Node* head) {
    return mergeSort(head);
}

int main() {
    vector<int> v = {2,3,-1,8,0,1};

    Node* head = convertArrToLL(v);

    Node* new_head = sortList(head);
    Node* temp = new_head;

    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}