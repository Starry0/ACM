#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF){
       if(t>100||t<0)cout<<"Score is error!"<<endl;
       else if(t>=90)cout<<'A'<<endl;
       else if(t>=80)cout<<'B'<<endl;
       else if(t>=70)cout<<'C'<<endl;
       else if(t>=60)cout<<'D'<<endl;
       else cout<<'E'<<endl;
    }
    return 0;
}
