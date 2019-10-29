#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* head2 = head->next;
        ListNode *t = head, *q = head2;
        ListNode* p;
        while (q && q->next){
            p = q->next;
            q->next = p->next;
            t->next = p;
            t = t->next;
            q = q->next;
        }
        t->next = head2;

        return head;
    }
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    Solution s;
    ListNode* q = s.oddEvenList(p);
    while (q){
        cout << q->val << " -> ";
        q = q->next;
    }
    cout << endl;

    return 0;
}
