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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root == NULL || root == p || root == q) return root;

    Node* left = lowestCommonAncestor(root->left,p,q);
    Node* right = lowestCommonAncestor(root->right,p,q);

    if(left && right) return root;
    else if(left) return left;
    return right;
}