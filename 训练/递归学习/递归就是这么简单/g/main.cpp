#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
map<char,int> mp;
vector<int> v;
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
    for(int i = 0; i < 10; i ++){
        mp['0'+i] = i;
    }
    string arr[210];
    //cout << f("111","222")<< endl;
    arr[1] = "1"; arr[2] = "2";
    for(int i = 3; i < 201; i++){
        arr[i] = f(arr[i-1], arr[i-2]);
    }
    int n;
    cin >> n;
    string s1;
    while(n--){
        cin >> s1;
        cout << arr[s1.length()] << endl;
    }
    return 0;
}
