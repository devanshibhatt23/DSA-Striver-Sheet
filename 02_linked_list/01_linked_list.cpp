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

int main() {
    vector<int> arr = {2,3,0,1};

    Node* y = new Node(arr[0]);
    cout << y << " " << y->data << " " << y->next << endl;

    // Node x = Node(arr[0], nullptr);
    // cout << x.data << " " << x.next << endl;
}