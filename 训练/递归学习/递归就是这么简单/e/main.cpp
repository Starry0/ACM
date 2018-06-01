#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
string arr[1010];
map<char,int> mp;
string f(string s,string ss){
    reverse(s.begin(),s.end());
    reverse(ss.begin(),ss.end());
    if(s.length()>ss.length())
        swap(s,ss);
    int a,b,sum,flags=0;
    string sss;
    for(int i=0;i<ss.length();++i){
        if(i>=s.length())
            a=0;
        else a=mp[s[i]];
        b=mp[ss[i]];
        sum=a+b+flags;
        if(sum>=10){
            sum-=10;
            flags=1;
        }
        else flags=0;
      //  v.push_back(sum);
        sss += '0' + sum;
    }
    if(flags)
        sss += '1';
    reverse(sss.begin(),sss.end());
    return sss;
}
int main(){
    int n;
    for(int i = 0; i < 10; i ++)
        mp['0'+i] = i;
    arr[0] = "1";arr[1] = "1";
    arr[2] = "2";arr[3] = "4";
    for(int i = 4; i < 1010; i++){
        arr[i] = f(f(arr[i-1], arr[i-2]),arr[i-4]);
    }
    //cout << arr[1000] << endl;
    while(~scanf("%d",&n)){
        cout << arr[n] << endl;
    }
    return 0;
}
