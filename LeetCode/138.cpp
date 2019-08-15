#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
		if(head == NULL) return;
        copy(head);
		rand(head);
		return split(head);
    }
	void copy(Node * head) {
		while(head) {
			Node* tmp = new Node(head->val, NULL, NULL);
			tmp->next = head->next;
			head->next = tmp;
			head = tmp->next;
		}
	}
	void rand(Node* head) {
		while(head) {
			Node* randTmp = head->next;
			if(head->random) randTmp->random = head->random->next;
			else randTmp->random = NULL;
			head = randTmp->next;
		}
	}
	Node *split(Node* head) {
		Node* newHead = head->next;
		Node* pNode = newHead;
		while(head) {
			head->next = pNode->next;
			head = head->next;
			if(head)pNode->next = head->next;
			else pNode->next = NULL;
			pNode = pNode->next;
		}
		return newHead;
	}
};

int main() {
	Node *a = new Node(1, NULL, NULL);
	Node *b = new Node(2, NULL, NULL);
	a->next = b; b->next = NULL;
	a->random = b; b->random = b;
	Solution sol;
	Node *pNode = sol.copyRandomList(a);

	return 0;
}