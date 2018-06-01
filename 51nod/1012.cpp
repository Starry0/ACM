    #include <stdio.h>
    #define ll long long
    ll gcd(ll a, ll b){
        return b?gcd(b,a%b):a;
    }
    ll lcm(ll a, ll b){
        return a/gcd(a,b)*b;
    }
    int main(){
        ll a, b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",lcm(a,b));
        return 0;
    }
