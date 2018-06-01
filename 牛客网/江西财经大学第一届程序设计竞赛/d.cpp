#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define ll long long
const int N = 11;
char str[N];
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> str;
        for(int i = 0; ; i ++) {
            if(str[0] =='S' && str[1] == 'S' && str[2] == 'R') {
                printf("%d\n",i);
                break;
            }
            if(str[2] == 'S') {
                if(str[1] == 'S') {
                    str[0] += 1;
                    str[1] = 'A';
                } else {
                    str[1] += 1;
                }
                str[2] = 'A';
            } else str[2] += 1;
        }
    }
    return 0;
}
