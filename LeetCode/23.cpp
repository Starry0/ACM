#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
		if(lists.size() == 1) return lists[0];
		if(lists.size() == 2) return mergeList(lists[0], lists[1]);
		vector<ListNode*> lists1, lists2;
		for(int i = 0; i < lists.size()/2; i ++) 
			lists1.push_back(lists[i]);
		for(int i = lists.size()/2; i < lists.size(); i ++) 
			lists2.push_back(lists[i]);
		return mergeList(mergeKLists(lists1), mergeKLists(lists2));
    }
private:
	ListNode* mergeList(ListNode* l1, ListNode* l2) {
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		ListNode* pNode = NULL;
		if(l1->val < l2->val) {
			pNode = l1;
			pNode->next = mergeList(l1->next, l2);
		} else {
			pNode = l2;
			pNode->next = mergeList(l1, l2->next);
		}
		return pNode;
	}
};
int main() {
	Solution s;
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(4);
	ListNode* c = new ListNode(5);
	ListNode* d = new ListNode(1);
	ListNode* e = new ListNode(3);
	ListNode* f = new ListNode(4);
	ListNode* g = new ListNode(2);
	ListNode* h = new ListNode(6);
	a->next = b; b->next = c; d->next = e;
	e->next = f; g->next = h;
	vector<ListNode*> vs;
	vs.push_back(a);
	vs.push_back(d);
	vs.push_back(g);
	ListNode* pNode = s.mergeKLists(vs);
	while(pNode != NULL) {
		cout << pNode->val << endl;
		pNode = pNode->next;
	}
	return 0;
}