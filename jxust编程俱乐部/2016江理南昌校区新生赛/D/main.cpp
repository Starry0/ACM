#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,k=0;
    cin>>a>>b;
    int z=max(a,b);
    for(int i=1;i<=6;i++)
        if(i>=z)
        k++;
    switch(k){
        case(0):{cout<<'0'<<'/'<<'1';break;}
        case(1):{cout<<'1'<<'/'<<'6';break;}
        case(2):{cout<<'1'<<'/'<<'3';break;}
        case(3):{cout<<'1'<<'/'<<'2';break;}
        case(4):{cout<<'2'<<'/'<<'3';break;}
        case(5):{cout<<'5'<<'/'<<'6';break;}
        case(6):{cout<<'1'<<'/'<<'1';break;}
    }
    return 0;
}
