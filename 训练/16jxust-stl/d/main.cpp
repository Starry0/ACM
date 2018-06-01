#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
map<string,int> mp;
int main()
{
    int n;
    string s,ss;
    while(~scanf("%d",&n)&&n){
        mp.clear();
        while(n--){
            cin>>s;
            mp[s]++;
        }
        map<string,int>::iterator it = mp.begin();
        ss = (*it).first;
        int maxn = (*it).second;
        ++it;
        for(; it != mp.end(); ++it){
            if((*it).second > maxn){
                maxn = (*it).second;
                ss = (*it).first;
            }
        }
        cout << ss << endl;

    }

    return 0;
}
