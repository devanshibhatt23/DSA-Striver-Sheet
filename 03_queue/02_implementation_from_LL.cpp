#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int data, Node* temp) {
        val = data;
        next = temp;
    }

    Node(int data) {
        val = data;
        next = NULL;
    }
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* temp = new Node(x, NULL);
    
    if(rear == NULL && front == NULL) {
        front = temp, rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if(front == NULL && rear == NULL) cout << "empty queue\n";
    else if(front == rear) {
        front = NULL, rear = NULL;
    }
    else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void display() {
    cout << "the queue is: ";
    if(front == NULL && rear == NULL) cout << "empty\n";
    else {
        Node* temp = front;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
}

void peek() {
    if(front == NULL && rear == NULL) cout << "empty queue\n";
    else {
        cout << "the front val is: " << front->val << "\n";
    }
}

int main() {
    enqueue(2);
    enqueue(3);
    peek();
    enqueue(-1);
    display();
    dequeue();
    display();
    peek();
    dequeue();
    dequeue();
    peek();
    display();
}