#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;
#define n 5

int q[5];
int front = -1, rear = -1;

void enqueue(int x) {
    if(front == -1 && rear == -1) {
        front++, rear++;
        q[rear] = x;
    }
    else if((rear+1) % n == front) {
        cout << "overflow\n";
    }
    else {
        rear = (rear+1) % n;
        q[rear] = x;
    }
}

void dequeue() {
    if(front == -1 && rear == -1) cout << "queue is empty\n";
    else if(front == rear) {
        rear = -1, front = -1;
    }
    else {
        front = (front+1)%n;
    }
}

void display() {
    if(front==-1 && rear==-1) cout << "queue is empty\n";
    else {
        cout << "queue is: ";
        int i = front;
        while(i != rear) {
            cout << q[i] << " ";
            i = (i+1)%n;
        }
        cout << q[rear] << "\n";
    }
}

void peek() {
    cout << "val at front is: ";
    if(front == -1 && rear == -1) cout << "queue is empty\n";
    else cout << q[front] << "\n";
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