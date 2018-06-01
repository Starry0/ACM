#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main() {
    string s;
    while(cin >> s){
        for(int i = 0; i < s.length(); i ++) {
            if(s[i] >= 'a' && s[i] < 'e') printf("a");
            else if(s[i] >= 'e' && s[i] < 'i') printf("e");
            else if(s[i] >= 'i' && s[i] < 'o') printf("i");
            else if(s[i] >= 'o' && s[i] < 'u') printf("o");
            else if(s[i] >= 'u' && s[i] < 'y') printf("u");
            else if(s[i] >= 'y') printf("y");
        }
        printf("\n");
    }
    return 0;
}
