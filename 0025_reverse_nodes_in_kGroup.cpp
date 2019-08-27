#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverse(ListNode* head){
        if (!head || !head->next)
            return head;
        ListNode *p = head, *q = head->next, *t = q;
        p->next = NULL;
        while (q){
            q = q->next;
            t->next = p;
            p = t;
            t = q;
        }

        return p;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        int n = 0;
        ListNode* p = head;
        while (p){
            n++;
            p = p->next;
        }
        int i;
        ListNode* h = new ListNode(0);
        h->next = head;
        p = h;
        while (n >= k){
            i = 0;
            ListNode* q = p;
            while (i < k){
                q = q->next;
                i++;
            }
            ListNode *p1 = p->next, *p2 = q->next;
            q->next = NULL;
            p->next = reverse(p1);
            while (p->next)
                p = p->next;
            p->next = p2;
            n -= k;
        }
        
        return h->next;
    }
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(5);
    int k = 3;
    Solution s;
    ListNode* r = s.reverseKGroup(p, k);
    while (r){
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;

    return 0;
}
