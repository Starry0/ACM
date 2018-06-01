#include <bits/stdc++.h>

using namespace std;
char s[505];
int main()
{
    int i,x='a';
    scanf("%s",s);
    for(i=0;s[i];i++){
        if(s[i]>x) return 0*puts("NO");
        if(s[i]==x)++x;
    }
    puts("YES");
    return 0;
}
