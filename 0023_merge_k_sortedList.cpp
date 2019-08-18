#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeLists(ListNode* head1, ListNode* head2){
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode dummy(-1);
        ListNode* p = &dummy;
        while (head1 && head2){
            if (head1->val <= head2->val){
                p->next = head1;
                head1 = head1->next;
            }
            else {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        if (!head1)
            p->next = head2;
        else 
            p->next = head1;

        return dummy.next;
    }
    
    ListNode* merge(vector<ListNode*>& lists, int left, int right){
        if (left < right){
            int mid = (left + right) / 2;
            ListNode* l1 = merge(lists, left, mid);
            ListNode* l2 = merge(lists, mid+1, right);
            return mergeLists(l1, l2);
        }
        else if (left == right)
            return lists[left];
        else
            return NULL;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};



int main(){
    vector<ListNode*> lists(3);
    lists[0] = new ListNode(1);
    lists[0]->next = new ListNode(4);
    lists[0]->next->next = new ListNode(5);
    lists[1] = new ListNode(1);
    lists[1]->next = new ListNode(3);
    lists[1]->next->next = new ListNode(4);
    lists[2] = new ListNode(2);
    lists[2]->next = new ListNode(6);
    
    Solution s;
    ListNode* p = s.mergeKLists(lists);
    while (p){
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;

    return 0;
}
