#include <iostream>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p = head, *t;
        while (p){
            t = p->next;
            p->next = new Node(p->val, NULL, NULL);
            p->next->next = t;
            p = t;
        }
        p = head;
        while (p){
            t = p->next;
            if (p->random)
                t->random = p->random->next;
            p = t->next;
        }
        Node* r = new Node(0, NULL, NULL);
        t = r;
        p = head;
        while (p && p->next){
            t->next = p->next;
            p->next = p->next->next;
            t = t->next;
            p = p->next;
        }
        t->next = NULL;

        return r->next;
    }
};



int main(){
    Node* p = new Node(1, NULL, NULL);
    p->next = new Node(2, NULL, NULL);
    p->random = p->next;
    p->next->random = p->next;
    Solution s;
    Node* r = s.copyRandomList(p);
    while (r){
        cout << "val " << r->val << "  random " << r->random->val << endl;
        r = r->next;
    }

    return 0;
}
