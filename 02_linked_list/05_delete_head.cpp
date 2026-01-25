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

Node* deleteHead(Node* head) {
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;

    // free(temp);
    delete temp;
    return head;
}

Node* deleteTail(Node* head) {
    if(head == NULL || head->next == nullptr) return NULL;

    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
} 

int main() {
    vector<int> v = {2,4,1,7,3};

    Node* head = convertArrToLL(v);
    Node* temp = head;

    // delete head
    // cout << (deleteHead(temp))->data << endl;

    // delete tail;
    printLL(deleteTail(head));
}