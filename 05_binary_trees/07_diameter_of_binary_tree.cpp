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

int max_height(Node* root, int &diameter) {
    if(root == NULL) return 0;

    int left_height = max_height(root->left, diameter);
    int right_height = max_height(root->right, diameter);

    diameter = max(diameter, left_height + right_height);

    return 1 + max(left_height,right_height);
}

int diameterOfBinaryTree(Node* root) {
    int diameter = 0;

    max_height(root,diameter);
    return diameter;
}

int main() {
    Node* root = NULL;
    root = createBintree(root);

    cout << diameterOfBinaryTree(root);
}