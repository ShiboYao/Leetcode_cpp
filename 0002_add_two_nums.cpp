#include <iostream>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* head = new ListNode(0);
        struct ListNode* r = head;
        int carry = 0, sum;

        while (l1 && l2){
            sum = l1->val + l2->val + carry;
            if (sum > 9){
                carry = 1;
                sum -= 10;
            }
            else
                carry = 0;
            r->next = new ListNode(sum);
            r = r->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1){
            sum = l1->val + carry;
            if (sum > 9){
                carry = 1;
                sum -= 10;
            }
            else
                carry = 0;
            r->next = new ListNode(sum);
            r = r->next;
            l1 = l1->next;
        }

        while (l2){
            sum = l2->val + carry;
            if (sum > 9){
                carry = 1;
                sum -= 10;
            }
            else
                carry = 0;
            r->next = new ListNode(sum);
            r = r->next;
            l2 = l2->next;
        }

        if (carry)
            r->next = new ListNode(1);

        return head->next;
    }
};


void display(struct ListNode* head){
    struct ListNode* t = head;
    while (t){
        cout << t->val << ' ';
        t = t->next;
    }
    cout << endl;
}


int main(){
    struct ListNode *l1, *l2;
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    display(l1);
    display(l2);

    Solution s;
    struct ListNode* head = s.addTwoNumbers(l1, l2);
    display(head);

    return 0;
}
