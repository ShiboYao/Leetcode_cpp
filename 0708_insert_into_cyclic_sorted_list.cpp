#include <iostream>
using namespace std;


class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next = NULL) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node* insert(Node* head, int insertVal){
        Node* n = new Node(insertVal, NULL);
        if (!head){
            n->next = n;
            return n;
        }
        Node* p = head;
        while (p->next != head){
            if (p->val <= insertVal && p->next->val >= insertVal)
                break;
            if ((p->val <= insertVal || p->next->val >= insertVal) && p->next->val < p->val)
                break;
            p = p->next;

        }
        n->next = p->next;
        p->next = n;

        return head;
    }
};


/*
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* n = new Node(insertVal, NULL);
        if (!head){
            n->next = n;
            return n;
        }   
        Node* p = head;
        if (p->val > insertVal){
            while (p->next->val >= p->val && p->next != head)
                p = p->next;
            if (p->next != head && p->next->val < insertVal)
                p = p->next;

        }   
        if (p->val < insertVal){
            while (p->val <= p->next->val && p->next->val < insertVal && p->next != head)
                p = p->next;
        }
    
        n->next = p->next;
        p->next = n;

        return head;
    }   
};
*/

int main(){
    Node* p = new Node(3);
    p->next = new Node(5);
    p->next->next = new Node(1);
    p->next->next->next = p;
    Solution s;
    Node* q = s.insert(p, 6);
    q = q->next;
    do {
        cout << q->val << " -> ";
        q = q->next;
    } while (q != p);
    cout << endl;

    return 0;
}
