#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;
#define n 5

int q[5];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == n-1) cout << "overflow\n";
    else if(front == -1 && rear == -1) {
        front++;
        rear++;
        q[rear] = x;
    }
    else {
        rear++;
        q[rear] = x;
    }
}

void dequeue() {
    if(front == -1 && rear == -1) cout << "queue is empty\n";
    else if(front == rear) {
        rear = -1, front = -1;
    }
    else {
        front++;
    }
}

void display() {
    if(front==-1 && rear==-1) cout << "queue is empty\n";
    
    for(int i=front; i<rear+1; i++) {
        cout << q[i] << " ";
    }
    cout << "\n";
}

void peek() {
    if(front == -1 && rear == -1) cout << "queue is empty\n";
    else cout << q[front] << "\n";
}

int main() {
    enqueue(2);
    enqueue(3);
    peek();
    enqueue(5);
    display();
    dequeue();
    display();
    peek();
    dequeue();
    peek();
}