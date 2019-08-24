//
// Created by starry on 2019/8/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[N], n, m, x;

struct Nod{
    int x, y;
}e[N];

bool cmp(const Nod& a, const Nod& b) {
    return a.y < b.y;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        a[x] = i;
    }
    int pos = 0;
    while(m--) {
        cin >> x;
        a[x] = pos--;
    }
    for(int i = 1; i <= n; i ++) {
        e[i].x = i;
        e[i].y = a[i];
    }
    sort(e+1,e+1+n,cmp);
    for(int i = 1; i <= n; i ++) {
        printf("%d ",e[i].x);
    }
//    printf("\n");
    return 0;
}