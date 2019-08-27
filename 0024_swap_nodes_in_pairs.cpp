#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* h = new ListNode(0);
        h->next = head;
        ListNode *p = h, *q = p->next;
        while (q && q->next){
            ListNode *p1 = q, *p2 = q->next->next;
            q = q->next;
            p->next = q;
            q->next = p1;
            p1->next = p2;
            p = p1;
            q = p->next;
        }

        return h->next;
    }
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    Solution s;
    ListNode*r  = s.swapPairs(p);
    while (r){
        cout << r->val << " ";
        r = r->next;
    }

    return 0;
}
