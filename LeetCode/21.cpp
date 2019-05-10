#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		ListNode* pNode;
		if(l1->val < l2->val) {
			pNode = l1;
			l1 = l1->next;
		} else {
			pNode = l2;
			l2 = l2->next;
		}
		ListNode* l3 = pNode;
		while(l1 != NULL && l2 != NULL) {
			if(l1->val < l2->val) {
				pNode->next = l1;
				pNode = l1;
				l1 = l1->next;
			} else {
				pNode->next = l2;
				pNode = l2;
				l2 = l2->next;
			}
		}
		if(l1 == NULL) pNode->next = l2;
		else pNode->next = l1;
		return l3;
    }
};
int main() {
	Solution sol;

	return 0;
}