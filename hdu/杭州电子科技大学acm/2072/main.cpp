#include <iostream>
#include <sstream>
#include <set>
#include <cstdio>
using namespace std;
set<string>mp;
int main()
{
    string s, sss;
    while(getline(cin,s)){
        if(s == "#")
            break;
        istringstream ss(s);
        while(ss>>sss){
            mp.insert(sss);
        }
        cout << mp.size() << endl;
        mp.clear();
    }
    return 0;
}
