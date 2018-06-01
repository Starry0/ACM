#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
const int MAX = 500010;
int a[MAX], b[MAX];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
    for(int i = 0; i < n; i ++) scanf("%d",&b[i]);
    sort(a,a+n);sort(b,b+n);
    ll sum = 0;
    for(int i = 0; i < n; i ++) sum += 1LL*a[i]*b[i];
    printf("%lld\n",sum);
    return 0;
}
