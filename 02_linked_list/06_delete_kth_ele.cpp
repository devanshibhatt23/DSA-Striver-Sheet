#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void printLL(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* convertArrToLL(vector<int> &v) {
    Node* head = new Node(v[0]);
    Node* mover = head;

    for(int i=1; i<v.size(); i++) {
        Node* temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

Node* deleteEleByVal(Node* head, int k) {
    if(head == NULL) return NULL;
    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr) {
        if(temp->data == k) {
            if(prev == nullptr) {
                head = head->next;
                free(temp);
                return head;
            }
            prev->next = prev->next->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> v = {2,4,1,7,3};

    Node* head = convertArrToLL(v);
    Node* temp = head;

    int k;
    cin >> k;
    // temp = deletekthEle(temp,k);
    // printLL(temp);

    printLL(deleteEleByVal(temp,k));
}