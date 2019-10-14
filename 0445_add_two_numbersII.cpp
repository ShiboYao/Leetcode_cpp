#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* h){
        if (!h || !h->next) return h;
        ListNode* p = h->next;
        h->next = NULL;
        while (p){
            ListNode* q = p->next;
            p->next = h;
            h = p;
            p = q;
        }

        return h;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1->val == 0) return l2;
        if (l2->val == 0) return l1;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* l = new ListNode(0);
        ListNode* h = l;
        bool carry = false;
        while (l1 && l2){
            int t = l1->val + l2->val + carry;
            if (t > 9){
                carry = true;
                t -= 10;
            }
            else
                carry = false;
            l->next = new ListNode(t);
            l = l->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* ll = l1?l1:l2;
        while (ll){
            int t = ll->val + carry;
            if (t > 9){
                carry = true;
                t -= 10;
            }
            else
                carry = false;
            l->next = new ListNode(t);
            l = l->next;
            ll = ll->next;
        }
        if (carry){
            l->next = new ListNode(carry);
            l = l->next;
        }
        
        return reverseList(h->next);
    }
};



int main(){
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution s;
    ListNode* l = s.addTwoNumbers(l1, l2);
    while (l){
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;

    return 0;
}
