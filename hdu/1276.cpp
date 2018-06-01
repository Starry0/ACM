#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main( ) {
	int n, m;
	cin >> n;
	while(n--) {
		queue<int> que, que1;
		cin >> m;
		for(int i = 1; i <= m; i ++) {
			que.push(i);
		}
		while(que.size() > 3) {
			int ans = 0;
			while(!que.empty()) {
				ans ++;
				if(ans%2 != 0) {
					que1.push(que.front());
				}
				que.pop();
			}

			if(que1.size() <= 3) break;
			ans = 0;
			while(!que1.empty()) {
				ans ++;
				if(ans%3 != 0) {
					que.push(que1.front());
				}
				que1.pop();
			}
			if(que.size() <= 3) break;
		}
		if(!que.empty()){
			int len = que.size();
			for(int i = 0; i < len-1; i ++) {
				cout << que.front() << ' ';
				que.pop();
			}
			cout << que.front() << endl;
		}else {
			int len = que1.size();
			for(int i = 0; i < len-1; i ++) {
				cout << que1.front() << ' ';
				que1.pop();
			}
			cout << que1.front() << endl;
		}
	}
	return 0;
}
