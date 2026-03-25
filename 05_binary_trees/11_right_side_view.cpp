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

vector<int> level_order(Node* root) {
    vector<vector<int>> vec;
    queue<Node*> q;

    vector<int> v, empty_vec;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            vec.push_back(v);
            v = empty_vec;
            if(!q.empty()) q.push(NULL);
        }
        else {
            v.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

    vector<int> right_view;
    for(auto &i : vec) {
        right_view.push_back(i[i.size()-1]);
    }

    return right_view;
}

vector<int> rightSideView(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    
    return level_order(root);
}