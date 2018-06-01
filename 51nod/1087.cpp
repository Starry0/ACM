#include <iostream>
#include <string.h>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
set<int> st;
int main() {
    for(int i = 1; i < 4e4; i ++) {
        st.insert(1 + i*(i-1)/2);
    }
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(st.count(n)) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
