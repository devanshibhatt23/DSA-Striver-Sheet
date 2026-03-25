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

bool is_symmetric(Node* left, Node* right) {
    if(left == NULL || right == NULL) return left==right;

    if(left->data != right->data) return 0;

    return is_symmetric(left->left, right->right) && 
    is_symmetric(left->right, right->left);
}

bool isSymmetric(Node* root) {
    return is_symmetric(root->left,root->right);
}