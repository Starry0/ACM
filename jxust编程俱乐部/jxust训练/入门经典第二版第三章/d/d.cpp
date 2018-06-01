#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn],b[maxn],c[maxn];
int main(){
    int A, B, n, i, k = 1, a[1020], b[1020], j, c[1020];
    while(scanf("%d",&n) && n){
        for(i = 0;i < n; i++){
            scanf("%d",&a[i]);
            c[i] = a[i];
        }
        int flag = 0;
        for(i = 0;i < n; i++){
            scanf("%d",&b[i]);
            if(b[i] != 0)
                flag = 1;
        }
        printf("Game %d:\n",k++);
        while(flag){
            A = 0;
            B = 0;
            for(i = 0;i < n; i++)
                if(a[i] == b[i]){
                    A++;
                    b[i] = a[i] = 0;
                }
            for(i = 0;i < n; i++){
                for(j = 0;j < n; j++){
                    if((a[i] == b[j]) && b[j]){
                        b[j] = a[i] = 0;
                        B++;
                        break;
                    }
                }
            }
            for(i = 0;i < n;i++)
                a[i] = c[i];
            printf("    (%d,%d)\n",A,B);
            flag = 0;
            for(i = 0;i < n; i++){
                scanf("%d",&b[i]);
                if(b[i] != 0)
                flag = 1;
            }
        }
    }
    return 0;
}
