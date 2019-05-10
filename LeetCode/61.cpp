#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if(head == NULL) return NULL;
        ListNode* pNode = head, *pNodePre = head;
		int len = 1;
		while(pNode->next != NULL) {
			len++;
			pNode = pNode->next;
		}
		k=len-k%len-1;
		int cnt = 0;
		while(cnt < k && pNodePre->next != NULL) {
			cnt++; pNodePre = pNodePre->next;
		}
		pNode->next = head;
		head = pNodePre->next;
		pNodePre->next = NULL;
		return head;
    }
};

int main() {
	Solution sol;

	return 0;
}