#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* pNode = head, *pNodePre = NULL;
// 		while(pNode != NULL) {
// 			ListNode* tmp = pNode->next;
// 			pNode->next = pNodePre;
// 			pNodePre = pNode;
// 			pNode = tmp;
// 		}
// 		return pNodePre;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL) return head;
// 		ListNode* pNode = reverseList(head->next);
// 		head->next->next = head;
// 		head->next = NULL;
// 		return pNode;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
		while(head) {
			ListNode* next = head->next;
			head->next = newHead;
			newHead = head;
			head = next;
		}
		return newHead;
    }
};
int main() {
	Solution sol;
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);
	ListNode *e = new ListNode(5);
	a->next = b; b->next = c; c->next = d;
	 d->next = e;
	ListNode *pNode = sol.reverseList(a);
	while(pNode != NULL) {
		printf("%d ",pNode->val);
		pNode = pNode->next;
	}
	return 0;
}