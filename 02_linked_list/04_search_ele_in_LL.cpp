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

bool searchEleInLL(Node* temp, int x) {
    while(temp != nullptr) {
        if(temp->data == x) return 1;
        temp = temp->next;
    }

    return 0;
}

int main() {
    vector<int> v = {2,3,0,1,9};

    Node* head = convertArrToLL(v);
    Node* temp = head;

    int x; 
    cin >> x;

    if(searchEleInLL(temp,x)) cout << "yes";
    else cout << "no";
}