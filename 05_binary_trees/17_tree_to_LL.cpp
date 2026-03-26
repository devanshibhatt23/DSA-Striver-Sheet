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

class Solution {
public:
    Node* prev = NULL;

    void flatten(Node* root) {
        if(root == NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};