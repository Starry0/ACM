// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// using namespace std;
// char str[4][4], ch, ch1;
// bool flag;
// int ans1, ans2;
// bool check(){
//     if(str[1][1] == ch && str[1][2] == ch && str[1][3] == ch) return true;
//     if(str[2][1] == ch && str[2][2] == ch && str[2][3] == ch) return true;
//     if(str[3][1] == ch && str[3][2] == ch && str[3][3] == ch) return true;
//     if(str[1][1] == ch && str[2][1] == ch && str[3][1] == ch) return true;
//     if(str[1][2] == ch && str[2][2] == ch && str[3][2] == ch) return true;
//     if(str[1][3] == ch && str[2][3] == ch && str[3][3] == ch) return true;
//     if(str[1][1] == ch && str[2][2] == ch && str[3][3] == ch) return true;
//     if(str[1][3] == ch && str[2][2] == ch && str[3][1] == ch) return true;
//     return false;
// }
// void dfs(int x, int k, int len){
//     if(x > len) return ;
//     if(check()){
//         flag = true;
//         return ;
//     }
//     for(int i = 1; i <= 3; i ++) {
//         for(int j = 1; j <= 3; j ++) {
//             if(str[i][j] == '.'){
//                 if(k == 1){
//                     str[i][j] = ch;
//                     dfs(x+1,-k,len);
//                     str[i][j] = '.';
//                 }else {
//                     str[i][j] = ch1;
//                     dfs(x+1,-k,len);
//                     str[i][j] = '.';
//                 }
//             }
//         }
//     }
// }
// int main(){
//     int t;
//     scanf("%d",&t);
//     while(t--) {
//         for(int i = 1; i <= 3; i ++) cin >> str[i]+1;
//         cin>>ch;
//         if(ch == 'x') ch1 = 'o';
//         else ch1 = 'x';
//         flag = false;
//         ans1 = ans2 = 0;
//         for(int i = 1; i <= 3; i ++) {
//             for(int j = 1; j <= 3; j ++) {
//                 if(str[i][j] == ch) ans1++;
//                 else if(str[i][j] == ch1) ans2++;
//             }
//         }
//         if(ans1 > ans2) {
//             dfs(0,-1,4);
//         }else {
//             dfs(0,1,3);
//         }
//         if(flag) cout << "Kim win!\n";
//         else cout << "Cannot win!\n";
//         memset(str,0,sizeof(str));
//     }
//     return 0;
// }



#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char str[4][4], ch, ch1,xx,yy;
bool flag;
void setCh1(){
    if(str[1][1]=='.'&&((str[1][2]==ch&&str[1][3]==ch)||(str[2][1]==ch&&str[3][1]==ch)||(str[2][2]==ch&&str[3][3]==ch))){
        str[1][1] = ch1;
        xx = 1;yy = 1;return;
    }
    if(str[1][2]=='.'&&((str[1][1]==ch&&str[1][3]==ch)||(str[2][2]==ch&&str[3][2]==ch))){
        str[1][2] = ch1;
        xx = 1; yy = 2;return;
    }
    if(str[1][3]=='.'&&((str[1][2]==ch&&str[1][1]==ch)||(str[2][3]==ch&&str[3][3]==ch)||(str[2][2]==ch&&str[3][1]==ch))){
        str[1][3] = ch1;
        xx = 1; yy = 3;return;
    }
    if(str[2][1]=='.'&&((str[2][2]==ch&&str[2][3]==ch)||(str[1][1]==ch&&str[3][1]==ch))){
        str[2][1] = ch1;
        xx = 2; yy = 1;return;
    }
    if(str[2][2]=='.'&&((str[1][2]==ch&&str[3][2]==ch)||(str[2][1]==ch&&str[2][3]==ch)||(str[1][1]==ch&&str[3][3]==ch)||(str[1][3]==ch&&str[3][1]))){
        str[2][2] = ch1;
        xx = 2; yy = 2;return;
    }
    if(str[2][3]=='.'&&((str[2][1]==ch&&str[2][2]==ch)||(str[1][3]==ch&&str[3][3]==ch))){
        str[2][3] = ch1;
        xx = 2; yy = 3;return;
    }
    if(str[3][1]=='.'&&((str[3][2]==ch&&str[3][3]==ch)||(str[2][1]==ch&&str[1][1]==ch)||(str[2][2]==ch&&str[1][1]==ch))){
        str[3][1] = ch1;
        xx = 3; yy = 1;return;
    }
    if(str[3][2]=='.'&&((str[1][2]==ch&&str[2][2]==ch)||(str[3][1]==ch&&str[3][3]==ch))){
        str[3][2] = ch1;
        xx = 3; yy = 2;return;
    }
    if(str[3][3]=='.'&&((str[1][3]==ch&&str[2][3]==ch)||(str[3][1]==ch&&str[3][2]==ch)||(str[2][2]==ch&&str[1][1]==ch))){
        str[3][3] = ch1;
        xx = 3; yy = 3;return;
    }
    if(str[2][2] == '.'){
        str[2][2] = ch1;
        xx = 2; yy = 2;return;
    }
    for(int i = 1; i <= 3; i ++) {
        for(int j = 1; j <= 3; j ++) {
            if(str[i][j] == '.'){
                str[i][j] = ch1;
                xx = i; yy = j;return;
            }
        }
    }
}
bool check(){
    if(str[1][1] == ch && str[1][2] == ch && str[1][3] == ch) return true;
    if(str[2][1] == ch && str[2][2] == ch && str[2][3] == ch) return true;
    if(str[3][1] == ch && str[3][2] == ch && str[3][3] == ch) return true;
    if(str[1][1] == ch && str[2][1] == ch && str[3][1] == ch) return true;
    if(str[1][2] == ch && str[2][2] == ch && str[3][2] == ch) return true;
    if(str[1][3] == ch && str[2][3] == ch && str[3][3] == ch) return true;
    if(str[1][1] == ch && str[2][2] == ch && str[3][3] == ch) return true;
    if(str[1][3] == ch && str[2][2] == ch && str[3][1] == ch) return true;
    return false;
}
void dfs(int x, int k){
    if(x > 3) return;
    if(check()){
        flag = true;return;
    }
    for(int i = 1; i <= 3; i ++) {
        for(int j = 1; j <= 3; j ++) {
            if(str[i][j] == '.'){
                if(k == 1){
                    str[i][j] = ch;
                    dfs(x+1,-k);
                    str[i][j] = '.';
                }else {
                    setCh1();
                    dfs(x+1,-k);
                    str[xx][yy] = '.';
                }
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) {
        memset(str,0,sizeof(str));
        for(int i = 1; i <= 3; i ++) cin >> str[i] + 1;
        cin >> ch;
        if(ch == 'o') ch1 = 'x';
        else ch1 = 'o';
        flag = false;
        dfs(0,1);
        if(flag) cout << "Kim win!\n";
        else cout << "Cannot win!\n";
    }
    return 0;
}
