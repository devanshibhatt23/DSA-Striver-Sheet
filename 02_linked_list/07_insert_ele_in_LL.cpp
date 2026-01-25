#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void printLL(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
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

Node* insertAtHead(Node* head, int val) {
    Node* prev = new Node(val, head);
    return prev;
} 

Node* insertAtTail(Node* head, int val) {
    if(head == NULL) return new Node(val);

    Node* temp = head;

    while(temp->next != nullptr) temp = temp->next;
    Node* last = new Node(val);
    temp->next = last;

    return head;
} 

int main() {
    vector<int> v = {2,4,1,7,3};

    Node* head = convertArrToLL(v);
    Node* temp = head;

    head = insertAtHead(head,5);
    printLL(head);
    printLL(insertAtTail(head,5));
}