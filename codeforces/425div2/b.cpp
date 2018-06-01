#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+10;
char str1[MAX],str2[MAX];
int vis[27], n;
int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i ++)
        vis[s[i]] = 1;
    scanf("%s%d",str1,&n);
    for(int i = 1; i <= n; i ++) {
        scanf("%s",str2);
        bool flag = true;
        int len1 = strlen(str1), len2 = strlen(str2);
        for(int a = 0, b = 0; a < len1 && b < len2; a ++,b++){
            if(str1[a] == str2[b])continue;
            else if(str1[a] == '?' && vis[str2[b]]) continue;
            else if(str1[a] == '*'){
                if(vis[str2[b]]){
                    flag =false;break;
                }else if(!vis[str2[b]]){
                    while()
                }
            }
        }
    }
    return 0;
}
