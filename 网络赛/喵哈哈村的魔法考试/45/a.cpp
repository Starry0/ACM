#include <bits/stdc++.h>
using namespace std;
map<string,map<int,int> > mp;
int main(){
    mp["niuroumian"][0] = 8;
    mp["niuroumian"][1] = 10;
    mp["niuroumian"][2] = 12;
    mp["zajiangmian"][0] = 7;
    mp["zajiangmian"][1] = 9;
    mp["zajiangmian"][2] = 11;
    mp["jiandanmian"][0] = 8;
    mp["jiandanmian"][1] = 10;
    mp["jiandanmian"][2] = 12;
    mp["fangbianmian"][0] = 3;
    mp["fangbianmian"][1] = 5;
    mp["fangbianmian"][2] = 7;
    mp["roujiamo"][0] = 4;
    mp["roujiamo"][1] = 5;
    mp["roujiamo"][2] = 6;
    int n;
    while(cin>>n){
        int ans = 0;
        string s; int a;
        for(int i = 1; i <= n; i ++){
            cin>>s>>a;
            ans += mp[s][a];
        }
        cout << ans << endl;
    }
    return 0;
}
