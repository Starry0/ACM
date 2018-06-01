#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[7][5];
bool check() {
    for(int i = 0; i < 6; i ++) {
        int ans = 0;
        for(int j = 1; j < 4; j ++) {
            if(a[i][j] == a[i][j-1]) ans++;
        }
        if(ans != 3) return false;
    }
    return true;
}
bool check1() {
    if(!(a[0][0]==a[0][2]&&a[0][2]==a[3][1]&&a[3][1]==a[3][3]))return false;
    if(!(a[1][0]==a[1][2]&&a[1][2]==a[0][1]&&a[0][1]==a[0][3]))return false;
    if(!(a[2][0]==a[2][2]&&a[2][2]==a[1][1]&&a[1][1]==a[1][3]))return false;
    if(!(a[3][0]==a[3][2]&&a[3][2]==a[2][1]&&a[2][1]==a[2][3]))return false;
    if(!(a[4][0]==a[4][1]&&a[4][1]==a[4][2]&&a[4][2]==a[4][3]))return false;
    if(!(a[5][0]==a[5][1]&&a[5][1]==a[5][2]&&a[5][2]==a[5][3]))return false;
    return true;
}
bool check2() {
    if(!(a[0][0]==a[0][2]&&a[0][2]==a[1][1]&&a[1][1]==a[1][3]))return false;
    if(!(a[1][0]==a[1][2]&&a[1][2]==a[2][1]&&a[2][1]==a[2][3]))return false;
    if(!(a[2][0]==a[2][2]&&a[2][2]==a[3][1]&&a[3][1]==a[3][3]))return false;
    if(!(a[3][0]==a[3][2]&&a[3][2]==a[0][1]&&a[0][1]==a[0][3]))return false;
    if(!(a[4][0]==a[4][1]&&a[4][1]==a[4][2]&&a[4][2]==a[4][3]))return false;
    if(!(a[5][0]==a[5][1]&&a[5][1]==a[5][2]&&a[5][2]==a[5][3]))return false;
    return true;
}
bool check3() {
    if(!(a[0][0]==a[0][1]&&a[0][1]==a[0][2]&&a[0][2]==a[0][3]))return false;
    if(!(a[2][0]==a[2][1]&&a[2][1]==a[2][2]&&a[2][2]==a[2][3]))return false;
    if(!(a[1][0]==a[1][1]&&a[1][1]==a[5][1]&&a[5][1]==a[5][3]))return false;
    if(!(a[5][0]==a[5][2]&&a[5][2]==a[3][0]&&a[3][0]==a[3][1]))return false;
    if(!(a[3][2]==a[3][3]&&a[3][3]==a[4][0]&&a[4][0]==a[4][2]))return false;
    if(!(a[4][1]==a[4][3]&&a[4][3]==a[1][1]&&a[1][1]==a[1][3]))return false;
    return true;
}
bool check4() {
    if(!(a[0][0]==a[0][1]&&a[0][1]==a[0][2]&&a[0][2]==a[0][3]))return false;
    if(!(a[2][0]==a[2][1]&&a[2][1]==a[2][2]&&a[2][2]==a[2][3]))return false;
    if(!(a[1][0]==a[1][1]&&a[1][1]==a[4][0]&&a[4][0]==a[4][2]))return false;
    if(!(a[5][0]==a[5][2]&&a[5][2]==a[1][2]&&a[1][2]==a[1][3]))return false;
    if(!(a[3][2]==a[3][3]&&a[3][3]==a[5][1]&&a[5][1]==a[5][3]))return false;
    if(!(a[4][1]==a[4][3]&&a[4][3]==a[3][0]&&a[3][0]==a[3][1]))return false;
    return true;
}
bool check5() {
    if(!(a[1][0]==a[1][1]&&a[1][1]==a[1][2]&&a[1][2]==a[1][3]))return false;
    if(!(a[3][0]==a[3][1]&&a[3][1]==a[3][2]&&a[3][2]==a[3][3]))return false;
    if(!(a[0][0]==a[0][1]&&a[0][1]==a[5][2]&&a[5][2]==a[5][3]))return false;
    if(!(a[5][0]==a[5][1]&&a[5][1]==a[2][0]&&a[2][0]==a[2][1]))return false;
    if(!(a[2][2]==a[2][3]&&a[2][3]==a[4][2]&&a[4][2]==a[4][3]))return false;
    if(!(a[4][0]==a[4][1]&&a[4][1]==a[0][2]&&a[0][2]==a[0][3]))return false;
    return true;
}
bool check6() {
    if(!(a[1][0]==a[1][1]&&a[1][1]==a[1][2]&&a[1][2]==a[1][3]))return false;
    if(!(a[3][0]==a[3][1]&&a[3][1]==a[3][2]&&a[3][2]==a[3][3]))return false;
    if(!(a[0][0]==a[0][1]&&a[0][1]==a[4][2]&&a[4][2]==a[4][3]))return false;
    if(!(a[5][0]==a[5][1]&&a[5][1]==a[0][2]&&a[0][2]==a[0][3]))return false;
    if(!(a[2][2]==a[2][3]&&a[2][3]==a[5][2]&&a[5][2]==a[5][3]))return false;
    if(!(a[4][0]==a[4][1]&&a[4][1]==a[2][0]&&a[2][0]==a[2][1]))return false;
    return true;
}
int b[7];
int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(b,0,sizeof(b));
        for(int i = 0; i < 6; i ++) {
            for(int j = 0; j < 4; j ++) {
                scanf("%d", &a[i][j]);
                b[a[i][j]]++;
            }
        }
        for(int i = 1; i < 7; i ++) {
            if(b[i] == 0){
                printf("NO\n");
                continue;
            }
        }
        if(check() || check1() || check2() || check3() || check4() || check5() || check6()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
