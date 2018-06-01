#include<iostream>
#include<cmath>
using namespace std;
int countDigitOne(int n,long factor) {
        long count = 0;
       // long factor = 1;

        while (n / factor != 0) {
            long lower = n % factor;
            long cur = (n / factor) % 10;
            long higher = n / (factor * 10);

            if (cur < factor+1) {
                count += higher * factor;
                if (cur == factor) count += lower+1;
            } else {
                count += (higher+1) * factor;
            }
            factor *= 10;
        }
        return (int) count;
    }
int main() {
    int t,a,b,q;
    cin>>t;
    while(t--){
        cin>>a>>b>>q;
        int suma=0,sumb=0;
        suma=countDigitOne(a,q);
        sumb=countDigitOne(b,q);
        cout<<suma<<' '<<sumb<<endl;
        cout<<sumb-suma<<endl;
    }
    return 0;
}


