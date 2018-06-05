/*#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if(a < b) swap(a,b);
      a=(int)(k*(1+sqrt(5))/2.0);
    if(a == b)
        printf("0\n");
    else
        printf("1\n");
    return 0;
}
*/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b){int t;t=a;a=b;b=t;}
    if((int)((b-a)*(sqrt(5)+1)/2.0)==a)cout<<0<<endl;
    else cout<<1<<endl;
	return 0;
}
