#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
int x[550], y[550];
int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        set<pair<int,int> > st;
        for(int i = 0; i < n; i ++) {
            scanf("%d%d",&x[i],&y[i]);
            st.insert(make_pair(x[i],y[i]));
        }
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = i+1; j < n; j ++) {
                int nx = x[i]+x[j], dx = max(x[i],x[j])-min(x[i],x[j]);
                int ny = y[i]+y[j], dy = max(y[i],y[j])-min(y[i],y[j]);
                if((nx+dy)&1 || (ny+dx)&1) continue;
                int sg = ((x[i]-x[j])*(y[i]-y[j]) < 0)?1:-1;
                if(st.count(make_pair((nx+dy)/2,(ny+sg*dx)/2)) && st.count(make_pair((nx-dy)/2,(ny-sg*dx)/2)))
                    ans++,printf("%d %d\n%d %d\n",x[i],y[i],x[j],y[j] );
            }
        }
        printf("%d\n",ans/2);
    }
    return 0;
}
