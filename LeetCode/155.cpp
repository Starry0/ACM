#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st1.push(x);
		if(st2.empty()) st2.push(x);
		else st2.push(min(st2.top(), x));
    }
    
    void pop() {
        st1.pop();
		st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
private:
	stack<int> st1, st2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;
	minStack.pop();
	cout << minStack.top() << endl;
	cout << minStack.getMin() << endl;
	return 0;
}