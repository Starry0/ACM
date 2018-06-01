#include <iostream>
#include <stdio.h>
#include <string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX = 65555*2;
bool Hash[MAX];
int cover[MAX<<2], XOR[MAX<<2];
void FXOR(int rt){
	if(cover[rt] != -1)cover[rt]^=1;
	else XOR[rt] ^= 1;
}
void PushDown(int rt){
	if(cover[rt] != -1){
		cover[rt<<1] = cover[rt<<1|1] = cover[rt];
		XOR[rt<<1] = XOR[rt<<1|1] = 0;
		cover[rt] = -1;
	}
	if(XOR[rt]){
		FXOR(rt<<1);
		FXOR(rt<<1|1);
		XOR[rt] = 0;
	}
}
void update(char op, int LL, int RR, int l, int r, int rt){
	if(LL <= l && r <= RR){
		if(op == 'U'){
			cover[rt] = 1;
			XOR[rt] = 0;
		}else if(op == 'D'){
			cover[rt] = 0;
			XOR[rt] = 0;
		}else if(op == 'C' || op == 'S'){
			FXOR(rt);
		}
		return;
	}
	PushDown(rt);
	int m = (l+r)>>1;
	if(LL <= m)update(op,LL,RR,lson);
	else if(op == 'I' || op == 'C'){
		XOR[rt<<1] = cover[rt<<1] = 0;
	}
	if(m < RR)update(op,LL,RR,rson);
	else if(op == 'I' || op == 'C'){
		XOR[rt<<1|1] = cover[rt<<1|1] = 0;
	}
}
void query(int l, int r, int rt){
	if(cover[rt] == 1){
		for(int it = l; it <= r; it++){
			Hash[it] = true;
		}
		return;
	}else if(cover[rt] == 0)return;
	if(l == r) return;
	PushDown(rt);
	int m = (l+r)>>1;
	query(lson);
	query(rson);
}
int main(){
	cover[1] = XOR[1] = 0;
	char op, l, r;
	int a, b;
	while(~scanf("%c %c%d,%d%c\n",&op,&l,&a,&b,&r)){
		a<<=1, b<<=1;
		if(l == '(')a++;
		if(r == ')')b--;
		if(a > b){
			if(op=='C' || op == 'I'){
				cover[1] = XOR[1] = 0;
			}
		}else update(op,a,b,0,MAX,1);
	}
	query(0,MAX,1);
	bool flag = false;
	int s = -1,e;
	for(int i = 0; i <= MAX; i ++){
		if(Hash[i]){
			if(s == -1)s=i;
			e =i;
		}else{
			if(s != -1){
				if(flag)printf(" ");
				flag = true;
				printf("%c%d,%d%c",s&1?'(':'[',s>>1,(e+1)>>1,e&1?')':']');
				s=-1;
			}
		}
	}
	if(!flag)printf("empty set");
	return 0;
}



/*#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <cctype>
#include <vector>
#include <iterator>
#include <set>
#include <map>
#include <sstream>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define pf printf
#define sf scanf
#define spf sprintf
#define pb push_back
#define debug printf("!\n")
#define MAXN 65535*2
#define MAX(a,b) a>b?a:b
#define blank pf("\n")
#define LL long long
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define pqueue priority_queue
#define INF 0x3f3f3f3f

int n,m;

int a[MAXN<<4],col[MAXN<<4],ans;

bool vis[MAXN];

void FXOR(int x)
{
    if(a[x]!=-1) a[x]^=1;
    else col[x]^=1;
}


void PushDown(int rt)
{
    if(a[rt] != -1)
    {
        a[rt<<1] = a[rt<<1|1] = a[rt];
        col[rt<<1] = col[rt<<1|1] = 0;
        a[rt] = -1;
    }
    if(col[rt])
    {
        FXOR(rt<<1);
        FXOR(rt<<1|1);
        col[rt] = 0;
    }
}

void update(char val,int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        if(val == 'U')
        {
            a[rt] = 1;
            col[rt] = 0;
        }
        else if(val == 'D')
        {
            a[rt] = col[rt] = 0;
        }
        else if(val == 'C' || val == 'S')
        {
            FXOR(rt);
        }
        return;
    }
    PushDown(rt);
    int mid = (l + r)>>1;
    if (L <= mid)
    {
        update(val,L,R,l,mid,rt<<1);
    }
    else if(val == 'I' || val == 'C')
    {
        a[rt<<1] = col[rt<<1] = 0;
    }
    if(R > mid)
    {
        update(val,L,R,mid+1,r,rt<<1|1);
    }
    else if(val == 'I' || val == 'C')
    {
        a[rt<<1|1] = col[rt<<1|1] = 0;
    }
}

void query(int l,int r,int rt)
{
    if(a[rt] == 1)
    {
        for(int i = l;i<=r;i++) vis[i] = true;
        return;
    }
    else if(a[rt] == 0) return;
    if(l == r) return;
    PushDown(rt);
    int mid = (l + r)>>1;
    query(l,mid,rt<<1);
    query(mid+1,r,rt<<1|1);
}


int main()
{
    int r,t;
    char op,lchar,rchar;
    a[1] = col[1] = 0;
    while(~sf("%c %c%d,%d%c\n",&op,&lchar,&r,&t,&rchar))
    {
        r<<=1;
        t<<=1;
        if(lchar == '(') r++;
        if(rchar == ')') t--;
        update(op,r,t,0,MAXN,1);
    }
    query(0,MAXN,1);
    int s = -1,e;
    bool flag = false;
    for(int i=0;i<=MAXN;i++)
    {
        if(vis[i])
        {
            if(s == -1) s = i;
            e = i;
        }
        else
        {
            if(s!=-1)
            {
                if(flag) pf(" ");
                pf("%c%d,%d%c",s&1?'(':'[',s>>1,(e+1)>>1,e&1?')':']');
                s = -1;
                flag = true;
            }
        }
    }
    if(!flag) printf("empty set");
    return 0;

}*/