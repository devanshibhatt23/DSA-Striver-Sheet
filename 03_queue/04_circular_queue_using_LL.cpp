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
        rear->next = front;
    }
    else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
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
        rear->next = front;
    }
}

void display() {
    cout << "the queue is: ";
    if(front == NULL && rear == NULL) cout << "empty\n";
    else {
        Node* temp = front;
        while(temp->next != front) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << temp->val << "\n";
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
    enqueue(4);
    enqueue(5);
    enqueue(6);
    peek();
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
    enqueue(1);
    enqueue(8);
    display();
}