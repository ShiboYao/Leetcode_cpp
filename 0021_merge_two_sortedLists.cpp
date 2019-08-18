#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode dummy(1);
        ListNode* p = &dummy;
        while (l1 && l2){
            if (l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (!l1)
            p->next = l2;
        else
            p->next = l1;

        return dummy.next;
    }
};



int main(){
    ListNode *p1, *p2;
    p1 = new ListNode(1);
    p1->next = new ListNode(2);
    p1->next->next = new ListNode(3);
    p2 = new ListNode(1);
    p2->next = new ListNode(3);
    p2->next->next = new ListNode(4);

    Solution s;
    ListNode* r = s.mergeTwoLists(p1, p2);
    while (r){
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;

    return 0;
}
