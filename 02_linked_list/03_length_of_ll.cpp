#include <bits/stdc++.h>
#include "./common/Node.h"
#define ll long long
using namespace std;

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

int lengthOfLL(Node* head) {
    int ct = 0;
    
    while(head != nullptr) {
        ct++;
        head = head->next;
    }
    return ct;
}

int main() {
    vector<int> v = {2,3,0,1,9};

    Node* head = convertArrToLL(v);
    Node* temp = head;

    cout << lengthOfLL(temp) << endl;
}