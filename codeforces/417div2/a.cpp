#include <bits/stdc++.h>
#define ll long long
int a[6][6];
int flag[6];
using namespace std;

int main(){
    for(int i = 1; i <= 4; i ++){
        for(int j = 1; j <= 4; j ++){
            cin >> a[i][j];
        }
    }
    bool res = false;
    for(int i = 1; i <= 4; i ++){
            if(i == 1){
                if(a[i][1]){
                    flag[4] = 1;
                }
                if(a[i][2]){
                    flag[3] = 1;
                }
                if(a[i][3]){
                    flag[2] = 1;
                }
                if((a[i][4] && flag[1]) ||(a[i][4] && a[i][2])){
                    res = true;
                }
            }
            else if(i == 2){
                if(a[i][1]){
                    flag[1] = 1;
                }
                if(a[i][2]){
                    flag[4] = 1;
                }
                if(a[i][3]){
                    flag[3] = 1;
                }
                if((a[i][4] && flag[2]) ||(a[i][4] && a[i][2])){
                    res = true;
                }
            }
            else if(i == 3){
                if(a[i][1]){
                    flag[2] = 1;
                }
                if(a[i][2]){
                    flag[1] = 1;
                }
                if(a[i][3]){
                    flag[4] = 1;
                }
                if((a[i][4] && flag[3]) ||(a[i][4] && a[i][2])){
                    res = true;
                }
            }
            else if(i == 4){
                if(a[i][1]){
                    flag[3] = 1;
                }
                if(a[i][2]){
                    flag[2] = 1;
                }
                if(a[i][3]){
                    flag[1] = 1;
                }
                if((a[i][4] && flag[4]) ||(a[i][4] && a[i][2])){
                    res = true;
                }
            }
    }
    if(a[1][1]){
        flag[4] = 1;
    }
    if(a[1][2]){
        flag[3] = 1;
    }
    if(a[1][3]){
        flag[2] = 1;
    }
    if((a[1][4] && flag[1]) ||(a[1][4] && a[1][2])){
        res = true;
    }
    if(res)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
