#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *p = head, *q = head->next;
        head->next = NULL;
        while (q){
            p = q;
            q = q->next;
            p->next = head;
            head = p;
        }

        return p;
    }
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    Solution s;
    ListNode* q = s.reverseList(p);
    while (q){
        cout << q->val << " ";
        q = q->next;
    }
    cout << endl;

    return 0;
}
