#include <bits/stdc++.h>
using namespace std;

int main() {
    char s1,s2;
    int n;
    cin>>s1>>s2>>n;
    n%=4;
    if(n==0 || n == 2) printf("undefined\n");
    else if(n==1){
        if(s1==94&&s2==62||s1==62&&s2==118||s1==118&&s2==60||s1==60&&s2==94)printf("cw\n");
        else if(s1==94&&s2==60||s1==60&&s2==118||s1==118&&s2==62||s1==62&&s2==94)printf("ccw\n");
        else printf("undefined\n");
    }else if(n == 3){
        if(s1==94&&s2==60||s1==62&&s2==94||s1==118&&s2==62||s1==60&&s2==118)printf("cw\n");
        else if(s1==94&&s2==62||s1==62&&s2==118||s1==118&&s2==60||s1==60&&s2==94)printf("ccw\n");
        else printf("undefined\n");
    }
    return 0;
}
