#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;
#define n 5

int q[n];
int front = -1, rear = -1;

void insertFront(int x) {
    if(front == (rear+1)%n) cout << "queue is full\n";
    else if(front == -1 && rear == -1) {
        front++, rear++;
        q[front] = x;
    }
    else if(front == 0) {
        front = n-1;
        q[front] = x;
    }
    else {
        front--;
        q[front] = x;
    }
}

void insertRear(int x) {
    if(front == -1 && rear == -1) {
        front++, rear++;
        q[rear] = x;
    }
    else if(front == (rear+1)%n) cout << "queue is full\n";
    else {
        rear = (rear+1) % n;
        q[rear] = x;
    }
}

void deleteFront() {
    if(front == -1) cout << "queue is empty\n";
    else if(front == rear) {
        front = -1, rear = -1;
    }
    else if(front == n-1) front = 0;
    else front++;
}

void deleteRear() {
    if(front == -1) cout << "queue is empty\n";
    else if(front == rear) {
        front = -1, rear = -1;
    }
    else if(rear == 0) {
        rear = n-1;
    }
    else rear--;
}

void display() {
    cout << "the queue is: ";
    if(front == -1 && rear == -1) cout << "full\n";
    else {
        int i = front;
        while(i != rear) {
            cout << q[i] << " ";
            i = (i+1)%n;
        }
        cout << q[rear] << "\n";
    }
}

void getFront() {
    if(front == -1) cout << "queue is empty\n";
    else {
        cout << q[front] << "\n";
    }
}

void getRear() {
    if(front == -1) cout << "queue is empty\n";
    else {
        cout << q[rear] << "\n";
    }
}

int main() {
    insertFront(2);
    insertFront(3);
    insertRear(-1);
    insertRear(0);
    display();
    insertFront(5);
    insertFront(2);
    deleteFront();
    deleteRear();
    deleteFront();
    display();
    getRear();
}