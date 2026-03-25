#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data1, Node* left1, Node* right1) {
        data = data1;
        left = left1;
        right = right1;
    }

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* createBintree(Node* root) {
    int data;
    cout << "enter data:\n";
    cin >> data;

    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "enter data for inserting in left of " << data << "\n";
    root->left = createBintree(root->left);

    cout << "enter data for inserting in right of " << data << "\n";
    root->right = createBintree(root->right);

    return root;
}

bool isSameTree(Node* p, Node* q) {
    if(p == NULL || q == NULL) {
        if(p == q) return 1;
        return 0;
    }

    bool val = (p->data == q->data);
    bool left_check = isSameTree(p->left, q->left);
    bool right_check = isSameTree(p->right, q->right);

    if(val && left_check && right_check) return 1;
    return 0;
}