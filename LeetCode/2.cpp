#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l = new ListNode(0);
        ListNode *tmp = l;
        int sum = 0;
        while(l1 || l2) {
        	if(l1) {
        		sum += l1->val;
        		l1 = l1->next;
        	}
        	if(l2) {
        		sum += l2->val;
        		l2 = l2->next;
        	}
        	tmp->next = new ListNode(sum%10);
        	sum /= 10;
        	tmp = tmp->next;
        }
        if(sum) tmp->next = new ListNode(1);
        return l->next;
    }
};


int main(int argc, char const *argv[])
{
	Solution Sol;
	ListNode *l1, *l2;
	init(l1);
	init(l2);
	Sol.addTwoNumbers(l1,l2);
	return 0;
}