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

Node* deepestNodes(Node* root) {
    Node* ans = root;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL) {
            if(!q.empty()) q.push(NULL);
        }
        else {
            if(temp->left && temp->right) ans = temp;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return ans;
}

int main() {
    Node* root = NULL;
    root = createBintree(root);

    cout << ((deepestNodes(root))->data);
}
// 1 3 7 -1 -1 11 -1 -1 5 4 -1 -1 -1
// 1 7 -1 -1 -8 -1 -1 0 -7 -1 -1 9 -1 -1