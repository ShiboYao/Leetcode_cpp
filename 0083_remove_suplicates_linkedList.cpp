#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *p = head, *q = head->next;
        while (q){
            while (q && p->val == q->val)
                q = q->next;
            p->next = q;
            p = q;
        }

        return head;
    }
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(3);
    Solution s;
    ListNode* q = s.deleteDuplicates(p);
    while (q){
        cout << q->val << ' ';
        q = q->next;
    }
    cout << endl;

    return 0;
}
