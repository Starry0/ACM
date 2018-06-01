#include <iostream>

using namespace std;
float f(int n){
    float sn=0;
    for(int i=1;i<=n;i++)
        sn+=1.0/i;
    return sn;
}
int main()
{
    int k;
    while(cin>>k){
            int n=1,m=1;
        while(m){
            if(f(n)>=k){
                cout<<n<<endl;
                m=0;
            }
            n++;
        }
    }
    return 0;
}
