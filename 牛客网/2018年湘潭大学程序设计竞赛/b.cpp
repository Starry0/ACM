#include <bits/stdc++.h>
#define ll long long
using namespace std;
char str[10][10] = {"012345","6789AB","CDEFGH",
                "IJKLMN","OPQRST","UVWXYZ"};
char str1[550];
int ans1[10],ans2[10];
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> str1;
        int MAX = 0;
        for(int i = 0; str1[i]; i ++) {
            for(int j = 0; j < 6; j ++) {
                for(int k = 0; k < 6; k ++) {
                    if(str[j][k] == str1[i]) {
                        ans1[j]++;
                        ans2[k]++;
                    }
                }
            }
        }
        for(int i = 0; i < 6; i ++) {
            for(int j = 0; j < 6; j ++) {
                MAX = max(MAX,ans1[i]+ans2[j]);
            }
        }
        for(int i = 0; i < 6; i ++) {
            for(int j = 0; j < 6; j ++) {
                if(ans1[i]+ans2[j] == MAX)
                    cout << str[i][j];
            }
        }
        cout << endl;
        memset(ans1,0,sizeof(ans1));
        memset(ans2,0,sizeof(ans2));
        memset(str1,0,sizeof(str1));
    }
    return 0;
}
