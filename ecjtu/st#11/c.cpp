#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#define ll long long
using namespace std;
const int MAX = 1000010;
int a[MAX];
map<int,int> mp;
set<int> st;
int main() {
    int p;
    while(scanf("%d",&p) !=EOF) {
        for(int i = 1; i <= p; i ++) {
            scanf("%d",&a[i]);
            st.insert(a[i]);
        }
        int k = st.size();
        st.clear();
        int l = 1, r = 1, minn = MAX*10;
        while(r <= p) {
            st.insert(a[r]);
            mp[a[r]] ++;
            if(st.size() == k) {
                while(mp[a[l]] >= 2) {
                    mp[a[l]]--;l++;
                }
                if(r-l+1 < minn) minn = r-l+1;
            }
            r++;
        }
        printf("%d\n",minn);
        st.clear();
        mp.clear();
        memset(a,0,sizeof(a));
    }
    return 0;
}
