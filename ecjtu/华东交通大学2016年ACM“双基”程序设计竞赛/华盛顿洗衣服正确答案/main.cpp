#include<stdio.h>
//#include<bits/stdc++.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<sstream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#include<limits.h>
#define inf 0x3fffffff
#define INF 0x3f3f3f3f
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long
#define ULL unsigned long long
using namespace std;
string s[10010];
int pos[10010];
int main()
{
    int n,m;
    int a;
    while(cin>>n>>m)
    {
        memset(pos,0,sizeof(pos));
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        for(int i=1; i<=n; i++)
        {
            int cnt=0;
            for(int j=1; j<=n; j++)
            {
                if(s[j].find(s[i])!=-1)
                {
                    cnt++;
                }
            }
            pos[i]=cnt;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>a;
            cout<<pos[a]<<endl;
        }
    }
    return 0;
}
