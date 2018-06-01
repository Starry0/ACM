#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
const int N = 1010;
char str[N], str1[N];
set<int> st, st1;
set<int> ::iterator it;
int main() {
    int n, m, len;
    cin >> n >> m;
    cin >> str+1 >> str1+1;
    for(int j = 1; str[j]; j ++) st1.insert(j);
    for(int i = 1; i <= m-n+1; i ++) {
        st.clear();
        for(int j = 1; j <= n; j ++) {
            if(str[j] != str1[j+i-1]) {
                st.insert(j);
            }
        }
        if(st.size() < st1.size()) {
            st1.clear();
            for(it = st.begin(); it != st.end(); it ++) {
                st1.insert((*it));
            }
        }
    }
    printf("%d\n",len=st1.size());
    it = st1.begin();
    for(int i = 1; it != st1.end(); ++it, ++i) {
        printf("%d%c", (*it), (i == len ?'\n':' '));
    }
    return 0;
}
