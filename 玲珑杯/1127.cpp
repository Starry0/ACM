#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    char c;
    string s;
    while((c=getchar())!=EOF){
        if(c == ' ' || c == '\n'){
            if(s != ""){
                reverse(s.begin(),s.end());
                cout << s ;
            }
            s = "";
            putchar(c);
        }else s +=c;
    }
    if(s != ""){
        reverse(s.begin(),s.end());
        cout << s ;
    }
    return 0;
}
