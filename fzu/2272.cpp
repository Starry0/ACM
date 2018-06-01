#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t, n, m;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        int x = (m-2*n)/2;
        printf("%d %d\n",x,n-x);
    }
    return 0;
}
