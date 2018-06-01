#include <iostream>
#include <set>
#include <sstream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    string s,s1;
    char c;
    set<string> ss;
    while(getline(cin,s)){
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(isalpha(s[i]))
                s[i] = tolower(s[i]);
            else s[i] = ' ';
        }
        istringstream sss(s);
        while(sss>>s1) ss.insert(s1);
    }
    set<string>::iterator it = ss.begin();
    for(;it != ss.end();++it){
        cout << (*it) <<endl;
    }
    return 0;
}
