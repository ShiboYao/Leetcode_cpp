#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode* p = new ListNode(-1);
        p->next = head;
        head = p;
        while (m > 1){
            p = p->next;
            m--;
            n--;
        }
        ListNode *q = p->next, *tail = p->next;
        ListNode *pre = q;
        q = q->next;
        ListNode* t = q;
        while (n > 1){
            q = q->next;
            t->next = pre;
            pre = t;
            t = q;
            n--;
        }
        p->next = pre;
        tail->next = q;

        return head->next;
    }
};



int main(){
    int m = 2, n = 4;
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* r = s.reverseBetween(p, m, n);
    while (r){
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;

    return 0;
}
