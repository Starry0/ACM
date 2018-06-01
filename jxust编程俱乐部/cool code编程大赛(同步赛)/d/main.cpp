#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(cin>>n){
        for(int i = 2; i <=2*n; i++){
            if(__gcd(2*n-2,i)==1){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
