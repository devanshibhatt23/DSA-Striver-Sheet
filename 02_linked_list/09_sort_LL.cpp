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
    if(head == NULL) return NULL;
    vector<int> v;
    Node* temp = head;

    while(temp) {
        v.push_back(temp->val);
        temp = temp->next;
    }

    sort(v.begin(), v.end());
    Node* new_head = new Node(v[0]);
    Node* head_to_ret = new_head;

    for(int i=1; i<v.size(); i++) {
        Node* nex = new Node(v[i]);
        new_head->next = nex;
        new_head = nex;
    }

    return head_to_ret;
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