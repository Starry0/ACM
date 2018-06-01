#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    set<int> st,st1;
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        if(x == 1) st.insert(y);
        if(y == 1) st.insert(x);
        if(x == n) st1.insert(y);
        if(y == n) st1.insert(x);
    }
    set<int>::iterator it;
    for(it = st.begin(); it != st.end(); it ++) {
        if(st1.count((*it))){
            return 0*printf("POSSIBLE\n");
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
