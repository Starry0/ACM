#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
char mp[N][N];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int R,C,I,r1,r2,c1,c2;
        char clo[3];
        cin>>R>>C>>I;
        memset(mp,0,sizeof(mp));
        for(int i=0;i<I;i++){
            cin>>r1>>c1>>r2>>c2>>clo;
            for(int i=r1;i<=r2;i++){
                for(int j=c1;j<=c2;j++){
                    mp[i][j]=clo[0];
                }
            }
        }
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(mp[i][j])
                    cout<<mp[i][j];
                else cout<<'.';
            }
            cout<<endl;
        }
    }
    return 0;
}
