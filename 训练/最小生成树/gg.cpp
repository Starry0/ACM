#include <iostream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
const int N = 550;
double a[N][2];
int fa[N*N];
struct Nod{
    int l, r;
    double w;
}e;
bool operator < (Nod a, Nod b){
    return a.w > b.w;
}
void init(){
    for(int i = 1; i < N*N; i ++){
        fa[i] = i;
    }
}
int find(int x){
    return fa[x] = (fa[x] == x) ? x : find(fa[x]);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        init();
        int k = 0;
        double sum[110];
        priority_queue<Nod> que;
        int n, m;
        scanf("%d%d",&m,&n);
        for(int i = 1; i <= n; i ++){
            scanf("%lf%lf",&a[i][0],&a[i][1]);
        }
        for(int i = 1; i <= n; i ++){
            for(int j = i+1; j <= n; j ++){
                double d = sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
                e.l = i; e.r = j; e.w = d;
                que.push(e);
            }
        }
        while(que.size()){
            e = que.top();
            que.pop();
            int a = find(e.l);
            int b = find(e.r);
            if(a != b){
                fa[a] = b;
                sum[k++] = e.w;
            }
        }
        // double ans = 0;
        sort(sum,sum+k);
        printf("%.2lf\n",sum[k-2]);
    }
    return 0;
}
