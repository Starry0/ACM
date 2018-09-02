#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 150010;
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main() {
	int n, Q;
	while(scanf("%d%d", &n, &Q) != EOF){
		int op, w, u, val, v;
		deque<int>que[n+1];
		while(Q--) {
			op = read();
	        if(op == 1){
	            u = read();w = read();val = read();
	            if(w == 0){
	                que[u].push_front(val);
	            }
	            else{
	                que[u].push_back(val);
	            }
	        }
	        if(op == 2){
	            u = read();w = read();
	            if(que[u].empty()){
	                printf("-1\n");
	            }
	            else{
		            if(w == 0){
		                printf("%d\n", que[u].front());
		                que[u].pop_front();
		            }
		            else{
		                printf("%d\n",que[u].back());
		                que[u].pop_back();
		            }
	            }
	        }
	        if(op == 3){
	            u = read();v = read();w = read();
	            if(w == 0){
		            while(!que[v].empty()){
		                int tmp =que[v].front();
		                que[v].pop_front();
		                que[u].push_back(tmp);
		            }
	            }
	            if(w == 1){
	                while(!que[v].empty()){
		                int tmp =que[v].back();
		                que[v].pop_back();
		                que[u].push_back(tmp);
	            	}
	            }
	        }
		}
		for(int i = 1; i <= n; i ++) que[i].clear();
	}
	return 0;
}