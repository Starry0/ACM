#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,x1,x[11],ss[11],q=0,l=1;
        cin>>n>>x1;
        m=log10(x1)+1;
        int x2=x1;
        while(x2>0){
            ss[q++]=x2%10;
            x2=x2/10;
        }
        for(int i=0;i<n-m;i++){
            if(i==0){
                for(int j=1;j<10;j++){
                    for(int w=0;ss[w];w++){
                        if(j==ss[w]){
                            l=0;
                            break;
                        }
                    }
                    if(l){
                        x[i]=j;
                    }
                }
            }
            else{
                for(int j=0;j<10;j++){
                    for(int w=0;ss[w];w++){
                        if(j==ss[w]||j==x[0]){
                            l=0;
                            break;
                        }
                    }
                    if(l){
                        x[i]=j;
                    }
                }
            }
        }
        for(int i=0;i<n-m;i++)
            cout<<x[i];
        cout<<x1<<endl;
    }
    return 0;
}
