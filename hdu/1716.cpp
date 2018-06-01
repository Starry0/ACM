#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 5;
int a[N];
int main() {
    int n, m, k = 1, ans;
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]) {
        if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) break;
        if(k != 1) printf("\n");
        int flag = 1, ans;
        do{
            if(a[0] == 0)continue;
            if(flag) flag = 0;
            else if(ans == a[0]) printf(" ");
            else printf("\n");
            printf("%d%d%d%d",a[0],a[1],a[2],a[3]);
            ans = a[0];
        }while(next_permutation(a, a+4));
        printf("\n");
        k++;
    }
    return 0;
}
