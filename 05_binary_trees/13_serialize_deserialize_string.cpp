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

void serialize(Node* root) {
    string s = "";
    queue<Node*> q;

    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) s.push_back('#');
        else {
            int x = temp->data;
            while(x) {
                s.push_back('0' + (x % 10));
                x /= 10;
            }

            q.push(temp->left);
            q.push(temp->right);
        }
    }

    cout << s << "\n";
}

// Node* deserialize(string data) {
    
// }

int main() {
    Node* root = NULL;
    root = createBintree(root);

    serialize(root);
}
// 3 8 1 -1 -1 -1 6 -1 2 -1 -1