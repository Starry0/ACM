#include <stdio.h>
#include <stack>
using namespace std;
stack<int> st;
int main() {
	st.push(12);
	st.push(22);
	st.push(14);
	printf("%d\n",st.top());
	printf("%d\n",st.size());
	printf("%d\n",st.empty());
	st.pop();
	printf("%d\n",st.top());
	return 0;
}