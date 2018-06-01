#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
#pragma comment(linker, "/sTACK:1024000000,1024000000")
#define lowbit(x) (x&(-x))
#define max(x,y) (x>=y?x:y)
#define min(x,y) (x<=y?x:y)
#define MAX 100000000000000000
#define MOD 1000000007
#define pi acos[j](-1.0)
#define ei exp(1)
#define PI 3.1415926535
#define ios() ios[j]::sync_with_stdio(true)
#define INF 1044266558
#define mem(a) (memset(a,0,sizeof(a)))
typedef long long ll;
int main()
{
    double a=1,b=1,x;
    double ans=0.0;
    double pos=0.0;
    scanf("%lf",&x);
    for(int i=1;;i++)
    {
        a*=x;
        b*=i;
        ans+=pow(-1,i+1)*a*1.0/b;
        if(fabs(ans-pos)<=1e-8) break;
        pos=ans;
    }
    printf("%.8lf\n",ans+1);
    return 0;
}
