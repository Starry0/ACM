#include <iostream>
#include <string.h>
#include <stdio.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 2e4+10;
int *ran, r[MAX], sa[MAX], height[MAX], wa[MAX], wb[MAX], wm[MAX];
bool cmp(int *r, int a, int b, int l) {
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r, int *sa, int n, int m) {
    int *x = wa, *y = wb, *t;
    for(int i = 0; i < m; i ++) wm[i] = 0;
    for(int i = 0; i < n; i ++) wm[x[i]=r[i]]++;
    for(int i = 1; i < m; i ++) wm[i] += wm[i-1];
    for(int i = n-1; i >= 0; i --) sa[--wm[x[i]]] = i;
    for(int i = 0, j = 1, p = 0; p < n; j<<=1,m = p) {
        for(p = 0, i = n-j; i < n; i ++) y[p++] = i;
        for(int i = 0; i < n; i ++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(int i = 0; i < m; i ++) wm[i] = 0;
        for(int i = 0; i < n; i ++) wm[x[y[i]]]++;
        for(int i = 0; i < m; i ++) wm[i] += wm[i-1];
        for(int i = n-1; i >= 0; i --) sa[--wm[x[y[i]]]] = y[i];
        for(t=x,x=y,y=t,i=p=1,x[sa[0]]=0; i < n; ++i) {
            x[sa[i]] = cmp(y,sa[i],sa[i-1],j)?p-1:p++;
        }
    }
    ran = x;
}
void calheight(int *r, int *sa, int n) {
    for(int i=0,j=0,k=0;i < n; height[ran[i++]]=k){
        for(k?--k:0,j=sa[ran[i]-1];r[i+k] == r[j+k];++k) {
        }
    }
}
int main() {
    int n;
    while(scanf("%d",&n)&&n) {
        for(int i = 0; i < n; i ++) scanf("%d",&r[i]);
        for(int i = 0; i < n-1; i ++) r[i] = r[i+1] - r[i] + 100;
        r[--n] = 0;
        da(r,sa,n+1,200);
        calheight(r,sa,n);
        int l = 1, r = n+1, m, L, R;
        bool flag = false;
        while(l <= r) {
            m = (l+r)>>1;
            L = INF, R = -INF,flag=false;
            for(int i = 1; i <= n; i ++) {
                if(height[i] >= m) {
                    L = min(L,sa[i]);
                    L = min(L,sa[i-1]);
                    R = max(R,sa[i]);
                    R = max(R,sa[i-1]);
                }else {
                    if(L+m+1 <= R) flag = true;
                    L = INF, R = -INF;
                }
            }
            if(L+m+1 <= R) flag = true;
            if(flag) l = m+1;
            else r = m-1;
        }
        if(l >= 5)printf("%d\n",l);
        else printf("0\n");
    }
    return 0;
}
