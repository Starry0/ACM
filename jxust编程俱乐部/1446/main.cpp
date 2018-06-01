#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    string a9[4]={"laopanorz","xiaoaiorz","huihuiorz","wenbaoorz"};
    string a10[3]={"laifangorz","ismdeeporz","mengmeiorz"};
    string a11[2]={"yuanshaoorz","liangshuorz"};
    int n;
    char name[15];
    scanf("%d%s",&n,name);
    if(n==9){
        for(int i=0;i<4;i++){
            if(name[i]==a9[0][i]){
                cout<<a9[0]<<endl;
                return 0;
            }
            if(name[i]==a9[1][i]){
                cout<<a9[1]<<endl;
                return 0;
            }
            if(name[i]==a9[2][i]){
                cout<<a9[2]<<endl;
                return 0;
            }
            if(name[i]==a9[3][i]){
                cout<<a9[3]<<endl;
                return 0;
            }

        }
        if(name[5]=='n'){
            cout<<a9[0]<<endl;
            return 0;
        }
        if(name[5]=='o'){
            cout<<a9[3]<<endl;
            return 0;
        }
        if(name[4]=='u'){
            cout<<a9[2]<<endl;
            return 0;
        }
        cout<<a9[1]<<endl;
        return 0;
    }
    if(n==10){
        for(int i=0;i<5;i++){
            if(name[i]==a10[0][i]){
                cout<<a10[0]<<endl;
                return 0;
            }
            if(name[i]==a10[1][i]){
                cout<<a10[1]<<endl;
                return 0;
            }
            if(name[i]==a10[2][i]){
                cout<<a10[2]<<endl;
                return 0;
            }
        }
        if(name[6]=='i'){
                cout<<a10[2]<<endl;
                return 0;
            }
            if(name[6]=='p'){
                cout<<a10[1]<<endl;
                return 0;
            }
            cout<<a10[0]<<endl;
            return 0;
    }
    if(n==11){
        for(int i=0;i<8;i++){
            if(i==2||i==3)
                continue;
            if(name[i]==a11[0][i]){
                cout<<a11[0]<<endl;
                return 0;
            }
            if(name[i]==a11[1][i]){
                cout<<a11[1]<<endl;
                return 0;
            }
        }
    }
    return 0;
}
