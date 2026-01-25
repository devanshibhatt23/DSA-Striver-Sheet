#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;
#define n 5

int st[n];
int top = -1;

void push(int x) {
    if(top == n-1) cout << "stack is full\n";
    else {
        top++;
        st[top] = x;
    }
}

void pop() {
    if(top == -1) cout << "stack is empty\n";
    else {
        top--;
    }
}

void getTop() {
    if(top == -1) cout << "stack is empty\n";
    else {
        cout << st[top];
    }
}

void display() {
    int temp = top;
    cout << "stack is: ";
    if(temp == -1) cout << "empty\n";
    while(temp != -1) {
        cout << st[temp] << " ";
        temp--;
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