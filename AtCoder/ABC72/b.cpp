#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
char str[N];
int main() {
    cin >> str;
    for(int i = 0; str[i];  i++) {
        if(i %2 == 0) printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}
