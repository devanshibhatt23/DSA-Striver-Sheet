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

int maxdepth(Node* root) {
    if(root == NULL) return 0;
    int len = 0;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            len++;
            if(!q.empty()) q.push(NULL);
        }
        else {
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return len;
}

int maxDepth(Node* root) {
    if(root == NULL) return 0;
    int len = 1 + max(maxDepth(root->left), maxDepth(root->right));

    return len;
}

int main() {
    Node* root = NULL;
    root = createBintree(root);

    cout << maxDepth(root) << "\n";
}
// 1 3 7 -1 -1 11 -1 -1 5 4 -1 -1 -1