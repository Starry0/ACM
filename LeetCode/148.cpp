#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
		ListNode *fast = head, *slow = head;
		ListNode *pPre = slow;
		while(fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			pPre = slow;
			slow = slow->next;
		}
		pPre->next = NULL;
		return merge(sortList(head), sortList(slow));
    }
private:
	ListNode* merge(ListNode* l1, ListNode* l2) {
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		if(l1->val < l2->val) {
			l1->next = merge(l1->next, l2);
			return l1;
		} else {
			l2->next = merge(l1, l2->next);
			return l2;
		}
	}
};

int main() {
	Solution sol;
	ListNode *p1 = new ListNode(3);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(0);
	ListNode *p4 = new ListNode(-4);
	p1->next = p2;p2->next = p3;
	p3->next = p4;
	ListNode *pNode = sol.sortList(p1);
	while(pNode != NULL) {
		printf("%d ",pNode->val);
		pNode = pNode->next;
	}
	return 0;
}