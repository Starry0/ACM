#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        ll ans=0;
        if(y<0&&abs(y)>abs(x)){
            ans+=x-y;
            x=y;
        }//��
        else if(x<0&&abs(x)>abs(y)){
            ans+=(-x-y);
            y=-x;
        }//��
        else if(y>0&&abs(y)>abs(x)){
            ans+=(y-x);
            x=y;
        }//��
        else if(x>0&&abs(x)>abs(y)){
            ans+=(x+y);
            y=(-x+1);
            x--;
        }//��
        while(x!=0&&y!=0){
            if(x>0&&y>0&&x==y){
                //y=3*y/2;x--;
                ans+=2*y;
                y=(-y+1);x--;
            }//����
            else if(x>0&&y<0&&y==-x){
                ans+=2*x;
                x=-x;
            }//����
            else if(x<0&&y<0&&x==y){
                y=-y;
                ans+=2*y;
            }//����
            else if(x<0&&y>0&&y==-x){
                x=-x;
                ans+=2*x;
            }//����

        }
        cout<<ans<<endl;
    }
    return 0;
}
