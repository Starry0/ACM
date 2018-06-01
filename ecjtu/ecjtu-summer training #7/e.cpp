// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <string.h>
// #define ll long long
// using namespace std;
//
// int main(){
//     ll a, n, b, x, y, t;
//     cin>>n>>a>>b;
//     for(int i=0;i<n;i++){
//        int x;
//        cin>>x;
//        t=x*a/b;
//        if(t*b%a==0)y=t*b/a;
//        else y=t*b/a+1;
//        cout<<x-y<<" ";
//    }
//    cout<<endl;
//    return 0;
// }


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define ll long long
using namespace std;

int main(){
    ll n, a, b, num;
    scanf("%lld%lld%lld",&n,&a,&b);
    for(int i = 1; i <= n; i ++) {
        scanf("%lld",&num);
        printf("%lld%c",(num*a)%b,i==n?'\n':' ');
    }
    return 0;
}
