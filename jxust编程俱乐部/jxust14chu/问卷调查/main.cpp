#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    float M=m;
    char S[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>S[i][j];
    for(int i=0;i<m;i++)
    {
        float a=0,b=0,c=0,d=0;
        for(int j=0;j<n;j++)
        {
            if(S[j][i]=='A')a++;
            else if(S[j][i]=='B')b++;
            else if(S[j][i]=='C')c++;
            else if(S[j][i]=='D')d++;
        }
        cout<<setiosflags(ios::fixed)<<setprecision(2);
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    }
    return 0;
}
