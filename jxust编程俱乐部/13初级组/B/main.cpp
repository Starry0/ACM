#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n){
        char a[2*n+1][2*n+1];
        for(int i=0;i<2*n+1;i++)
        for(int j=0;j<2*n+1;j++)
            a[i][j]='.';
        int m=n;a[n][n]='*';
        for(int i=0;i<n;i++){
            a[n][m-1]='*';
            a[m-1][n]='*';
            m--;
        }
        m=n;
        for(int i=0;i<n;i++){
            a[n][m+1]='*';
            a[m+1][n]='*';
            m++;
        }
        m=n;int k=n;
        for(int i=0;i<n;i++){
            a[m+1][k-1]='*';
            m++;k--;
        }
        m=n;
        for(int i=0;i<n;i++){
            a[m+1][m+1]='*';
            m++;
        }
        for(int i=0;i<2*n+1;i++)
        for(int j=0;j<2*n+1;j++){
            cout<<a[i][j];
            if(j==2*n)cout<<endl;
        }
        cin>>n;
    }
    return 0;
}
