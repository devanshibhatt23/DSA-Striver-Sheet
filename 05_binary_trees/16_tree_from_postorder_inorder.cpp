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

Node* func(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int> &hash, int post_start, int post_end, int in_start, int in_end) {
    if(post_start > post_end || in_start > in_end) return NULL;

    Node* root = new Node(postorder[post_end]);

    int root_idx = hash[postorder[post_end]];
    int right_part = in_end - root_idx;

    root->left = func(inorder, postorder, hash, post_start, post_end-right_part-1, in_start, root_idx-1);

    root->right = func(inorder, postorder, hash, post_end-right_part, post_end-1, root_idx+1, in_end);

    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();

    unordered_map<int,int> hash;
    for(int i=0; i<n; i++) hash[inorder[i]] = i;

    return func(inorder,postorder,hash,0,n-1,0,n-1);
}