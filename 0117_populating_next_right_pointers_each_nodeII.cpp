#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};


class Solution {
public:
    void util(vector<Node*>& stack){
        if (stack.empty())
            return;
        Node* p = stack.back();
        vector<Node*> stack2;
        stack.pop_back();
        if (p->left)
            stack2.push_back(p->left);
        if (p->right)
            stack2.push_back(p->right);
        while (!stack.empty()){
            p->next = stack.back();
            stack.pop_back();
            p = p->next;
            if (p->left)
                stack2.push_back(p->left);
            if (p->right)
                stack2.push_back(p->right);        
        }
        while (!stack2.empty()){
            p = stack2.back();
            stack.push_back(p);
            stack2.pop_back();
        }
        util(stack);
    }


    Node* connect(Node* root) {
        if (!root)
            return root;
        vector<Node*> stack;
        stack.push_back(root);
        util(stack);

        return root;
    }
};



int main(){
    Node* p = new Node(1, NULL, NULL, NULL);
    p->left = new Node(2, NULL, NULL, NULL);
    p->right = new Node(3, NULL, NULL, NULL);
    Solution s;
    Node* r = s.connect(p);
    //cout << r->next << endl;
    cout << r->left->next->val << endl;
    //cout << r->right->next << endl;

    return 0;
}
