#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

/*
class Solution {
public:
    vector<Node*> util(Node* r){
        if (!r)
            return {NULL, NULL};
        vector<Node*> t = {r, r};
        if (r->right){
            vector<Node*> right = util(r->right);
            right[0]->left = r;
            r->right = right[0];
            t[1] = right[1];
        }
        if (r->left){
            vector<Node*> left = util(r->left);
            left[1]->right = r;
            r->left = left[1];
            t[0] = left[0];
        }

        return t;
    }

    Node* treeToDoublyList(Node* root) {
        if (!root)
            return NULL;
        util(root);
        Node *head = root, *tail = root;
        while (head->left)
            head = head->left;
        while (tail->right)
            tail = tail->right;
        head->left = tail;
        tail->right = head;        

        return head;
    }
};
*/


class Solution {
    vector<Node*> stack;
public:
    void util(Node* r){
        if (!r)
            return;
        util(r->left);
        stack.push_back(r);
        util(r->right);
    }

    Node* treeToDoublyList(Node* root){
        if (!root)
            return NULL;
        util(root);
        Node* tail = stack.back();
        Node* head = tail;
        while (!stack.empty()){
            head->left = stack.back();
            stack.back()->right = head;
            stack.pop_back();
            head = head->left;
        }
        head->left = tail;
        tail->right = head;

        return head;
    }
};



int main(){
    Node* p = new Node(4, NULL, NULL);
    p->left = new Node(2, NULL, NULL);
    p->right = new Node(5, NULL, NULL);
    p->left->left = new Node(1, NULL, NULL);
    p->left->right = new Node(3, NULL, NULL);
    Solution s;
    Node* head = s.treeToDoublyList(p);
    Node* tail = head->left;
    while (head != tail){
        cout << head->val << " ";
        head = head->right;
    }
    cout << tail->val << " ";
    cout << endl;

    return 0;
}
