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

Node* func(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int> &hash, int pre_start, int pre_end, int in_start, int in_end) {
    if(pre_start > pre_end || in_start > in_end) return NULL;

    Node* root = new Node(preorder[pre_start]);

    int root_idx = hash[preorder[pre_start]];
    int left_part = root_idx - in_start;

    root->left = func(preorder, inorder, hash, pre_start+1, pre_start+left_part, in_start, root_idx-1);

    root->right = func(preorder, inorder, hash, pre_start+left_part+1, pre_end, root_idx+1, in_end);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    unordered_map<int,int> hash;

    for(int i=0; i<n; i++) {
        hash[inorder[i]] = i;
    }

    return func(preorder,inorder,hash,0,n-1,0,n-1);
}