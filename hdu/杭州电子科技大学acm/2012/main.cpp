#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF&&x||y){
        int ans=0;
        for(int i=x;i<=y;i++){
            int sn=i*i+i+41;
            for(int j=2;j<sn;j++){
                if(sn%j==0){
                    ans++;
                    break;
                }
            }
        }
        if(ans==0)printf("OK\n");
        else printf("Sorry\n");
    }
    return 0;
}
