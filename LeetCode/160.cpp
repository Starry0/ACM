#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(headA == NULL || headB == NULL) return NULL;
        int len1 = 0, len2 = 0;
		ListNode* pNodeOne = headA, *pNodeTwo = headB;
		while(pNodeOne != NULL) {
			len1++;
			pNodeOne = pNodeOne->next;
		}
		while(pNodeTwo != NULL) {
			len2++;
			pNodeTwo = pNodeTwo->next;
		}
		pNodeOne = headA, pNodeTwo = headB;
		while(len1 > len2) {
			len1--;
			pNodeOne = pNodeOne->next;
		}
		while(len2 > len1) {
			len2--;
			pNodeTwo = pNodeTwo->next;
		}
		while(pNodeOne != pNodeTwo && len1-- > 0)  {
			pNodeOne = pNodeOne->next;
			pNodeTwo = pNodeTwo->next;
		}
		return pNodeOne;
    }
};

int main() {
	Solution sol;

	return 0;
}