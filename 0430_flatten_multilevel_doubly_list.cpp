#include <iostream>
using namespace std;


class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev = NULL, Node* _next = NULL, Node* _child = NULL) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};


class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
            return head;
        Node* h = head;
        while (h && h->child == NULL)
            h = h->next;
        if (h){
            Node* t = flatten(h->next);
            h->next = flatten(h->child);
            h->child = NULL;
            h->next->prev = h;
            while (h->next)
                h = h->next;
            h->next = t;
            if (t)
                t->prev = h;
        }

        return head;
    }
};



int main(){
    Node* p = new Node(1);
    p->next = new Node(2);
    p->next->next = new Node(3);
    p->next->next->child = new Node(7);
    Solution s;
    Node* r = s.flatten(p);
    while (r){
        cout << r->val << "->";
        r = r->next;
    }
    cout << endl;

    return 0;
}
