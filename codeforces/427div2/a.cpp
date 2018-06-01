#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, v1, v2, t1, t2;
    cin>>s>>v1>>v2>>t1>>t2;
    int a = v1*s+2*t1, b = v2*s+2*t2;
    if(a < b)printf("First\n");
    else if(a == b) printf("Friendship\n");
    else printf("Second\n");
    return 0;
}
