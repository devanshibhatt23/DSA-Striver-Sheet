#include <bits/stdc++.h>
#include <queue>
#include <stack>
#define ll long long
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int d) {
        val = d;
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

vector<int> inorderTraversal(Node* root) {
    vector<int> v;
    stack<Node*> s;
    Node* temp = root;
    
    while(!s.empty() || temp) {
        while(temp) {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();
        v.push_back(temp->val);

        temp = temp->right;
    }

    return v;
}

vector<int> preorderTraversal(Node* root) {
    stack<Node*> s;
    vector<int> v;
    s.push(root);

    while(!s.empty()) {
        Node* temp = s.top();
        s.pop();

        if(temp == NULL) break;
        else {
            v.push_back(temp->val);
            if(temp->right) s.push(temp->right);
            if(temp->left) s.push(temp->left);
        }
    }

    return v;
}

vector<int> postorderTraversal(Node* root) {
    stack<Node*> s;
    vector<int> v;
    s.push(root);

    while(!s.empty()) {
        Node* temp = s.top();
        s.pop();

        if(temp == NULL) break;
        else {
            v.push_back(temp->val);
            if(temp->left) s.push(temp->left);
            if(temp->right) s.push(temp->right);
        }
    }

    reverse(v.begin(), v.end());
    return v;
}

int main() {
    Node* root = NULL;
    root = createBintree(root);

    // vector<int> v_in = inorderTraversal(root);
    // vector<int> v_pre = preorderTraversal(root);
    vector<int> v_post = postorderTraversal(root);

    for(int i : v_post) cout << i << " ";
    cout << "\n";
}
// 1 3 7 -1 -1 11 -1 -1 5 4 -1 -1 -1