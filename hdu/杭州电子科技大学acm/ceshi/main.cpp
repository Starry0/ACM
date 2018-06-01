#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
map<char,int> mp;
string f(string s, string ss){
    string sss;
    if(s.length() < ss.length()) swap(s,ss);
    int len1 = s.length();
    int len2 = ss.length();
    reverse(s.begin(),s.end());reverse(ss.begin(),ss.end());
    int a, b, c,flag = 0;
    for(int i = 0; i < len1; i++){
        a = mp[s[i]];
        if(i < len2) b = mp[ss[i]];
        else b = 0;
        c = a + b;
        if(c>9){
            c -= 10;
            sss += '0' + c + flag;
            flag = 1;
         }
         else{
            sss += '0' + c + flag;
            flag = 0;
         }
    }
    if(flag)sss+='1';
    reverse(sss.length(),sss.length());
    return sss;
}

int main(){
    for(int i = 0; i < 10; i ++){
        mp['0'+i] = i;
    }
    //cout << f("111","222")<< endl;
    int n;
    while(cin >> n){
      //  cout << arr[n] << endl;
    }
    return 0;
}
