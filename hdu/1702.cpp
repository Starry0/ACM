#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int n, m, x;
	char str[5];
	cin >> n;
	while(n--) {
		cin >> m >> str;	
		if(str[2] == 'F') {
			queue<int> que;
			while(m--) {
				cin >> str; 
				if(str[0] == 'I'){
					cin >> x;
					que.push(x);
				}
				else {
					if(!que.empty()) {
						cout << que.front() << endl;
						que.pop();
					} else cout << "None\n";
				}
			}
		} else {
			stack<int> st;
			while(m--) {
				cin >> str;
				if(str[0] == 'I'){
					cin >> x;
					st.push(x);
				}
				else {
					if(!st.empty()) {
						cout << st.top() << endl;
						st.pop();
					} else cout << "None\n";
				}
			}
		}
	}
	return 0;
}
