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

Node* insertAtKthPos(Node* head, int k, int val) {
    if(head==NULL) {
        return new Node(val);
    }
    if(k<=0) return head;
    if(k==1) {
        Node* temp = new Node(val, head);
        head = temp;
        return head;
    }
    
    Node* temp = head;
    int ct = 1;

    while(temp != nullptr) {
        if(ct == k-1) {
            Node* newNode = new Node(10, temp->next);
            temp->next = newNode;
        }
        temp = temp->next;
        ct++;
    } 
    return head;
}

Node* insertBeforeVal(Node* head, int val, int x) {
    if(head->data == x) {
        Node* temp = new Node(val, head);
        return temp;
    }

    Node* temp = head;

    while(temp->next != nullptr) {
        if(temp->next->data == x) {
            Node* newNode = new Node(val,temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> v = {2,4,1,7,3};

    Node* head = convertArrToLL(v);
    Node* temp = head;

    // printLL(insertAtKthPos(head,3,10));
    printLL(insertBeforeVal(head,10,3));
}