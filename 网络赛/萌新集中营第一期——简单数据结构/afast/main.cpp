#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;
const int MAXSIZE = 500510;
int a[1001];
int n, head[MAXSIZE], next[MAXSIZE];
struct SUM
{  
    int sum;
    int x, y;
} b[MAXSIZE];
int Hash(int s)
{
    int seed = (s >> 1) + (s << 1);
    return (seed & 0x7FFFFFFF) % 500503;
}
int insert(int s)
{
    int h = Hash(b[s].sum);
    int u = head[h];
    while(u)
    {
        if(b[u].sum == b[s].sum)
            return 0;
        u = next[u];
    }
    next[s] = head[h];
    head[h] = s;
    return 1;
}
int search(int x, int y)
{
    int h = Hash(a[x] - a[y]);
    int u = head[h];
    while(u)
    {
        if(a[x] - a[y] == b[u].sum
           && x != b[u].x
           && y != b[u].y
           && b[u].x != y
           && b[u].y != x ) // 判断a，b不能与c，d重复
            return 1;
        u = next[u];
    }
    return 0;
}
int main()
{
#ifdef test
    freopen("sample.txt", "r", stdin);
#endif
    int num;
    int max_;
    while(scanf("%d", &n), n)
    {
        max_ = -0x7FFFFFFF;
        num = 1;
        memset(head, 0, sizeof(head));
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                b[num].sum = a[i] + a[j];
                if(insert(num))
                {
                    b[num].x = i;
                    b[num].y = j;
                    ++num;
                }
            }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(i != j)
                {
                    if(search(i, j) && max_ < a[i])
                        max_ = a[i];
                }
        if(max_ == -0x7FFFFFFF)
            printf("no solution\n");
        else
            printf("%d\n",max_);
    }
    return 0;
}
