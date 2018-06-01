#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> t;
    while(t--) {
        cin >> n;
        string s;
        bool flag = true;
        while(n--) {
            cin >> s;
            if(s != "PERFECT") flag = false;
        }
        if(flag) printf("MILLION Master\n");
        else printf("NAIVE Noob\n");
    }
    return 0;
}
