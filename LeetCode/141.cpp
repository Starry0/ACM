#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
// 		if(head == NULL) return false;
//         ListNode* pNode = head, *pNodeTwo = head;
// 		while(pNodeTwo->next != NULL) {
// 			pNode = pNode->next;
// 			pNodeTwo = pNodeTwo->next;
// 			if(pNodeTwo->next != NULL) pNodeTwo = pNodeTwo->next;
// 			else return false;
// 			if(pNode == pNodeTwo) return true;
// 		}
// 		return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode* pfast = head, *pshow = head;
		while(pfast) {
			pfast = pfast->next;
			if(pfast) pfast = pfast->next;
			else return false;
			pshow = pshow->next;
			if(pfast == pshow) return true;
		}
		return false;
    }
};
int main() {
	Solution sol;

	return 0;
}