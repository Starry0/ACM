#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int week[] = {52,52,52,52,53,53,52};
    string s;
    int x;
    while(cin>>x>>s>>s){
        if(s == "month"){
            if(x <=29) cout << 12 <<endl;
            else if(x == 30) cout << 11 << endl;
            else if(x == 31) cout << 7 << endl;
        }
        else if(s == "week"){
            cout << week[x-1] << endl;
        }
    }
}
