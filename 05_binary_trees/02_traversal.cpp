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

void inorderTraversal(Node* root) {
    if(root == NULL) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if(root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void createFromLevelOrder(Node* &root) {
    queue<Node*> q;

    cout << "enter data\n";
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "enter left of " << temp->data << "\n";
        int leftd;
        cin >> leftd;

        if(leftd != -1) {
            temp->left = new Node(leftd);
            q.push(temp->left);
        }
        
        cout << "enter right of " << temp->data << "\n";
        int rightd;
        cin >> rightd;

        if(rightd != -1) {
            temp->right = new Node(rightd);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << "\n";
            if(!q.empty()) q.push(NULL);
        }
        else {
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> v;
    queue<Node*> q;

    if(root == NULL) return v;
    q.push(root);
    q.push(NULL);

    vector<int> vec, emp;

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            v.push_back(vec);
            vec = emp;
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

int main() {
    Node* root = NULL;
    root = createBintree(root);

    // inorderTraversal(root);
    // preorderTraversal(root);
    // postorderTraversal(root);

    // createFromLevelOrder(root);
    // levelOrderTraversal(root);

    // vector<vector<int>> v = levelOrder(root);
    // for(auto i : v) {
    //     for(auto j : i) cout << j << " ";
    //     cout << "\n";
    // }

    vector<vector<int>> v = levelOrder(root);
    int ans = INT_MIN, idx = -1;

    for(int i=0; i<v.size(); i++) {
        int sum = 0;
        for(int j=0; j<v[i].size(); j++) {
            sum += v[i][j];
        }
        ans = max(sum, ans);
        if(ans == sum) {
            idx = i+1;
        }
    }
    cout << idx;
}
// 1 3 7 -1 -1 11 -1 -1 5 4 -1 -1 -1
// 1 7 -1 -1 -8 -1 -1 0 -7 -1 -1 9 -1 -1