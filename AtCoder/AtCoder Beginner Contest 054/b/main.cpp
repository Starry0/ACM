#include <bits/stdc++.h>
using namespace std;
char a[101][101],b[101][101];
int main()
{
    memset(a,0,sizeof(a));memset(b,0,sizeof(b));
    int n,m,flag=1;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    for(int i=0;i<m;i++)
        scanf("%s",b[i]);
    if(m>n){
        cout<<"No"<<endl;
        return 0;
    }
    else {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==b[0][0]){
                    flag = 0;
                    for(int x=0;x<m;x++){
                        for(int y=0;y<m;y++){
                            if(a[i+x][j+y]!=b[x][y]){
                                flag = 1;
                                break;
                            }
                        }
                    }
                    if(flag==0){
                        cout<<"Yes"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
