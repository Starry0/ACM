#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
const  ll Gold[3] = { 618033988, 749894848, 204586834};
const int mod = 1000000000;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a, b;
        cin>>a>>b;
        if(a < b)swap(a,b);
        ll dist = a-b;
        ll pre = dist/mod, las = dist%mod;
        ll a1 = las*Gold[2];
        ll a2 = pre*Gold[2] + las*Gold[1] + a1/mod;
        ll a3 = pre*Gold[1] + las*Gold[0] + a2/mod;
        ll a4 = dist + pre*Gold[0] + a3/mod;
        cout << (a4==b?'B':'A') << endl;
    }
    return 0;
}
