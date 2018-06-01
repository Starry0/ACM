/*
后缀数组就是套模板求先应得数组，这题用到了两个数组，分别是sa[],height[];
sa[i]表示所有后缀按字典数排序后以s[i]开始的后缀排在第i位。height[i]表示
字典数为i和i-1后缀的的最长串的前缀。
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 2e5+10;
char str[MAX];
int s[MAX], sa[MAX], t[MAX], t2[MAX], c[MAX], n;
int rank1[MAX], height[MAX];

void build_sa(int m) {
    int *x = t, *y = t2;
    for(int i = 0; i < m; i ++) c[i] = 0;
    for(int i = 0; i < n; i ++) c[x[i]=s[i]] ++;
    for(int i = 1; i < m; i ++) c[i] += c[i-1];
    for(int i = n-1; i >= 0; i --) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for(int i = n-k; i < n; i ++) y[p++] = i;
        for(int i = 0; i < n; i ++) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(int i = 0; i < m; i ++) c[i] = 0;
        for(int i = 0; i < n; i ++) c[x[y[i]]]++;
        for(int i = 1; i < m; i ++) c[i] += c[i-1];
        for(int i = n-1; i >= 0; i --) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1;
        x[sa[0]] = 0;
        for(int i = 1; i < n; i ++)
            x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]?p-1:p++;
        if(p >= n)break;
        m = p;
    }
}
void getHeight() {
    int k = 0;
    for(int i = 0; i < n; i ++) rank1[sa[i]] = i;
    for(int i = 0; i < n; i ++) {
        if(k) k--;
        int j = sa[rank1[i]-1];
        while(s[i+k] == s[j+k]) k++;
        height[rank1[i]] = k;
    }
}
int main() {
    n = 0;
    int l1, l2;
    scanf("%s",str);
    l1 = strlen(str);
    for(int i = 0; i < l1; i ++) s[n++] = str[i] - 'a' + 1;
    s[n++] = 28;
    scanf("%s",str);
    l2 = strlen(str);
    for(int i = 0; i < l2; i ++) s[n++] = str[i] - 'a' + 1;
    s[n++] = 0;
    build_sa(30);
    getHeight();
    int maxn = 0;
    for(int i = 2; i < n; i ++) {
        if(maxn < height[i]) {
            if(sa[i] >= 0 && sa[i] < l1 && sa[i-1] > l1)
                maxn = height[i];
            if(sa[i-1] >= 0 && sa[i-1] < l1 && sa[i] > l1)
                maxn = height[i];
        }
    }
    printf("%d\n",maxn);
    return 0;
}
