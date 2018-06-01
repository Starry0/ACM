#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a==0&&b==0)
            break;
        int c=0,m=1;
        for(int i=0;i<100;i++){
            c=a*100+i;
            if(c%b==0){
                if(m==1){
                    if(i<10)
                    cout<<"0"<<i;
                    else cout<<i;
                    m=0;
                }
                else {
                    if(i<10)
                        cout<<' '<<"0"<<i;
                    else cout<<' '<<i;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
