#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode pNode1(0);
		ListNode pNode2(0);
		ListNode* pNodeA = &pNode1, *pNodeB = &pNode2;
		ListNode* ptrA = pNodeA, *ptrB = pNodeB;
		while(head) {
			if(head->val < x) {
				ptrA->next = head;
				ptrA = ptrA->next;
			} else {
				ptrB->next = head;
				ptrB = ptrB->next;
			}
			head = head->next;
		}
		ptrA->next = pNodeB->next;
		ptrB->next = NULL;
		return pNodeA->next;
    }
};
int main() {

	return 0;
}