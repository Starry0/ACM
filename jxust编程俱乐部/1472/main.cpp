#include <bits/stdc++.h>
using namespace std;
int main(){
    string s[] ={ " _     _  _     _  _  _  _  _ ",
                  "| |  | _| _||_||_ |_   ||_||_|",
                  "|_|  ||_  _|  | _||_|  ||_| _|"};
    int a,b,c,d;
    while(~scanf("%d%d%d%d",&a,&b,&c,&d)){
        for(int i = 0; i < 3; i++){
            cout<<s[i][a*3]<<s[i][a*3+1]<<s[i][a*3+2]
                <<s[i][b*3]<<s[i][b*3+1]<<s[i][b*3+2]
                <<s[i][c*3]<<s[i][c*3+1]<<s[i][c*3+2]
                <<s[i][d*3]<<s[i][d*3+1]<<s[i][d*3+2]<<endl;
        }
    }
    return 0;
}
