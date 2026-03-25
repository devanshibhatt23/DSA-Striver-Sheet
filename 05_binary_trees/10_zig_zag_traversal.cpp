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

vector<vector<int>> LevelOrder(Node* root) {
    vector<vector<int>> v;
    queue<Node*> q;

    if(root == NULL) return v;
    q.push(root);
    q.push(NULL);

    vector<int> vec, empty_vec;

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            v.push_back(vec);
            vec = empty_vec;
            if(!q.empty()) q.push(NULL);
        }
        else {
            vec.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

    return v;
}

vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> v = LevelOrder(root);

    for(int i=1; i<v.size(); i += 2) {
        reverse(v[i].begin(), v[i].end());
    }

    return v;
}