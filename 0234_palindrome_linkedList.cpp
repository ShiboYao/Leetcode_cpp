#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
private:
    void display(ListNode* p){
        while (p){
            cout << p->val << " -> ";
            p = p->next;
        }
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        int digit = 0;
        ListNode* p = head;
        while (p){
            p = p->next;
            digit++;
        }
        int half_digit = digit/2 - 1;
        p = head;
        while (half_digit){
            p = p->next;
            half_digit--;
        }
        ListNode* q = p->next;
        if (digit%2 != 0)
            p->next = new ListNode(q->val);
        else 
            p->next = NULL;
        head = reverse(head);
        while (head && q && head->val == q->val){
            head = head->next;
            q = q->next;
        }
        if (head || q)
            return false;
        else
            return true;
    }

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
};



int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    Solution s;
    bool r = s.isPalindrome(head);
    cout << r << endl;

    return 0;
}
