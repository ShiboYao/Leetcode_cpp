#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next && fast != slow){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return fast==slow;
    }
};



int main(){
    ListNode* p = new ListNode(3);
    p->next = new ListNode(2);
    p->next->next = new ListNode(0);
    p->next->next->next = p->next;
    Solution s;
    cout << s.hasCycle(p) << endl;

    return 0;
}
