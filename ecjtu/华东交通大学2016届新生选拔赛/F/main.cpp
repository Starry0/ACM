#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n;
    char c;
    while(scanf("%d",&n)!=EOF){
        int d=0,x=0;
        for(int i=0;i<n;i++){
            cin>>c;
            if(c>='A'&&c<='Z')
                d++;
            else if(c>='a'&&c<='z')
                x++;
        }
        if(d>0&&x>0)cout<<"I like A and a."<<endl;
        else if(d>0&&x==0)cout<<"I like A."<<endl;
        else if(d==0&&x>0)cout<<"I like a."<<endl;

    }
    return 0;
}
