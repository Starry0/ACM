#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = NULL;
        ListNode* result = head;
        int changeLen = n-m+1;
        while(head && --m) {
            pre = head;
            head = head->next;
        }
        ListNode* last = head;
        ListNode* newHead = NULL;
        while(head && changeLen) {
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
            changeLen--;
        }
        last->next = head;
        if(pre) {
            pre->next = newHead;
        } else {
            result = newHead;
        }
        return result;
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
	ListNode *pNode = sol.reverseBetween(a, 2, 4);
	while(pNode != NULL) {
		printf("%d ",pNode->val);
		pNode = pNode->next;
	}
	return 0;
}