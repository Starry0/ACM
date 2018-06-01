#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 50010;
struct Nod {
    int l, r;
}nod[N];
bool cmp(Nod a, Nod b) {
    if(a.l != b.l ) return a.l < b.l;
    else return a.r > b.r;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d %d", &nod[i].l, &nod[i].r);
    }
    sort(nod, nod+n, cmp);
    int ans = 0, i = 0, j;
    while(i < n) {
        j = i+1;
        while(nod[i].r > nod[j].l && j < n) {
            if(nod[j].r <= nod[i].r) {
                ans = max(ans, nod[j].r-nod[j].l);
            } else {
                ans = max(ans, nod[i].r-nod[j].l);
                break;
            }
            j++;
        }
        i++;
    }
    printf("%d\n",ans);
    return 0;
}
