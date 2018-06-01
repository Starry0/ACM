#include <iostream>
#include <cmath>
using namespace std;
int hwss(int n){
    int m=0,a,b,c,d,e,f;
    int l=log10(n)+1;
    switch(l){
        case 1:m=1;break;
        case 2:{a=n%10;b=n/10;}break;
        case 3:{a=n%10;c=n/100;b=(n-c*100)/10;}break;
        case 4:{a=n%10;d=n/1000;e=(n-d*1000)/100;b=(n/10)%10;}break;
        case 5:{a=n%10;b=(n/10)%10;c=(n/100)%10;d=(n/1000)%10;e=n/10000;}break;
        case 6:{a=n%10;b=(n/10)%10;c=(n/100)%10;d=(n/1000)%10;e=(n/10000)%10;f=n/100000;}break;
        default :m=0;
    }
    switch(l){
        case 1:break;
        case 2:{if(n==(a*10+b))m=1;}break;
        case 3:{if(n==(a*100+b*10+c))m=1;}break;
        case 4:{if(n==(a*1000+b*100+c*10+d))m=1;}break;
        case 5:{if(n==(a*10000+b*1000+c*100+d*10+e))m=1;}break;
        case 6:{if(n==(a*100000+b*10000+c*1000+d*100+e*10+f))m=1;}break;
        default :break;
    }
    return m;
}
int ss(int n){
    int m=1;
    if(n==1)m=0;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)m=0;
    return m;
}
int main()
{
    int a,b;
    cin>>a>>b;
    while(a!=0&&b!=0){
            int k=0;
        for(int i=a;i<=b;i++){
            if(hwss(i)&&ss(i))k++;
        }
        cout<<k<<endl;
        cin>>a>>b;
    }
    return 0;
}
