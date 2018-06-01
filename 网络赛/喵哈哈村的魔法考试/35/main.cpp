#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int a[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n)){
        for(int i = 0; i < n; i++)scanf("%d",a+i);
        sort(a,a+n);
        for(int i = 0; i < n; i++)
            printf("%d ",a[i]);
        cout << endl;
    }

    return 0;
}
