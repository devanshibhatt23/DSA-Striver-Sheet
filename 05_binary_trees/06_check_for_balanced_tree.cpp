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

int maxDepth(Node* root) {
    if(root == NULL) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    if(lh == -1 || rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
    return maxDepth(root) != -1;
}

int main() {
    Node* root = NULL;
    root = createBintree(root);

    cout << isBalanced(root);
}