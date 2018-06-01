
#include<stdio.h>
//#include<bits/stdc++.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<sstream>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits.h>
#define inf 0x3fffffff
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long
using namespace std;
const int maxn = 22;
int main()
{
    int t;
    int n;
    int i;
    int j;
    string s,ss;
    while(cin>>t)
    {
        while(t--)
        {
            string sss="";
            int ans;
            cin>>n>>s;
            for(i=0;i<n;i++)
            {
                string sss="";
                cin>>ss;
                ans=ss.find(".");
             //   cout<<ans<<endl;
                for(j=ans+1;j<ss.length();j++)
                {
                    sss+=ss[j];
                }
           //     cout<<sss<<endl;
                if(sss==s)
                {
                    cout<<ss<<endl;
                }
            }
        }
    }

    return 0;
}
