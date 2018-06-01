#include <iostream>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
map<int,multiset<int> > mx,my;
typedef map<int,multiset<int> > mmpp;
int f(mmpp &x, mmpp &y, int pos){
    int ans = x[pos].size();
    multiset<int>::iterator it = x[pos].begin();
    for(;it != x[pos].end(); ++it){
        y[(*it)].erase(pos);
    }
    x[pos].clear();
    return ans;
}
int main()
{
    int n, m;
    while(~scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0)
            break;
        int x, y, c, d;
        for(int i = 0; i < n; i++){
            scanf("%d%d",&x,&y);
            mx[x].insert(y);
            my[y].insert(x);
        }
        for(int i = 0; i < m; i++){
            scanf("%d%d",&c,&d);
            int ans = 0;
            if(c == 0) ans = f(mx,my,d);
            else ans = f(my,mx,d);
            printf("%d\n",ans);
        }
        printf("\n");
        mx.clear();
        my.clear();
    }
    return 0;
}
/*
HDU 4022
G++ 1296ms


*/

/*
#include<stdio.h>
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

// ����һ�� map,�� int �� һ�� multiset ������ӳ��
typedef map<int,multiset<int> > line;// ����>��һ��Ҫ�Ӹ��ո�
map<int,multiset<int> >mx;//����x�����Ӧ��map
map<int,multiset<int> >my;//����y�����Ӧ��map

int bomb(line &x,line &y,int pos)
{
    int ret=x[pos].size();
    multiset<int>::iterator it;//���ѧϰ��
    for(it=x[pos].begin();it!=x[pos].end();it++)
       y[*it].erase(pos);//multiset ȥ��һ��Ԫ��
    x[pos].clear();//���multiset
    return ret;
}
int main()
{
    int n,m;
    int c,d;
    int tx,ty;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        mx.clear();
        my.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&tx,&ty);
            mx[tx].insert(ty);
            my[ty].insert(tx);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&c,&d);
            int ans;
            if(c==0) ans=bomb(mx,my,d);
            else ans=bomb(my,mx,d);
            printf("%d\n",ans);
        }
        printf("\n");
    }
    return 0;
}
*/
