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

int max_sum(Node* root, int &maxi) {
    if(root == NULL) return 0;

    int left_sum = max(0,max_sum(root->left, maxi));
    int right_sum = max(0,max_sum(root->right, maxi));

    maxi = max(maxi, left_sum + right_sum + root->data);

    return root->data + max(left_sum, right_sum);
}

int maxPathSum(Node* root) {
    int ans = INT_MIN;
    max_sum(root,ans);
    return ans;
}

int main() {
    Node* root = NULL;
    root = createBintree(root);

    cout << maxPathSum(root);
}