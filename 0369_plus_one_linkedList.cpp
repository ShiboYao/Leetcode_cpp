#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
private:
    ListNode* reverse(ListNode* head){
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
public:
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        ListNode* p = head;
        int carry = 1;
        while (p){
            if (p->val + carry > 9){
                p->val = 0;
                p = p->next;
            }
            else
                break;
        }
        if (carry){
            if (p)
                p->val += 1;
            else {
                p = head;
                while (p->next)
                    p = p->next;
                p->next = new ListNode(1);
            }
        }
        head = reverse(head);

        return head;
    }
};



int main(){
    ListNode* p = new ListNode(1);
    p->next = new ListNode(9);
    Solution s;
    ListNode* q = s.plusOne(p);
    while (q){
        cout << q->val << ' ';
        q = q->next;
    }
    cout << endl;

    return 0;
}
