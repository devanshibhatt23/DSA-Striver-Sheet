#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;
#define n 5

class Node{
    public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

Node* top = NULL;

void push(int x) {
    Node* temp = new Node(x);

    if(top == NULL) {
        top = temp;
    }
    else {
        Node* tp = top;
        temp->next = tp;
        top = temp;
    }
}

void pop() {
    if(top == NULL) cout << "stack is empty\n";
    else {
        Node* t = top;
        top = top->next;
        delete t;
    }
}

void getTop() {
    if(top == NULL) cout << "stack is empty\n";
    else {
        cout << top->val << "\n";
    }
}

void display() {
    Node* temp = top;
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    push(2);
    push(5);
    push(3);
    push(4);
    display();
    pop(), pop(), pop();
    display();
    getTop();
}