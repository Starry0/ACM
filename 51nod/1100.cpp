//数据很水，暴力就过了。
// 也有nlogn的算法，斜率最大的那两个点一定是x点相邻的
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
struct Point{
    int x, y;
}p[N];
typedef pair<int,int> P;
std::vector<P> vs;
int main() {
    int n;
    double MAX = -111111;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> p[i].x >> p[i].y;
    for(int i = 1; i <= n; i ++) {
        for(int j = i+1; j <= n; j ++) {
            double a = (p[j].y-p[i].y)/(p[j].x-p[i].x);
            if(a > MAX) {
                MAX = a;
                vs.clear();
                vs.push_back(P(i,j));
            } else if(a == MAX) {
                vs.push_back(P(i,j));
            }
        }
    }
    for(int i = 0; i < vs.size(); i ++) {
        if(p[vs[i].first].x < p[vs[i].second].x)
            cout << vs[i].first << ' ' << vs[i].second << endl;
        else cout << vs[i].second << ' ' << vs[i].first << endl;
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
struct Point{
    int x, y;
    int id;
}p[N];
struct Nod{
    double k;
    int id1, id2;
}nod[N];
bool cmp1(Point &a, Point &b) {
    return a.x < b.x;
}
bool cmp2(Nod &a, Nod &b) {
    return a.k > b.k;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i+1;
    }
    sort(p,p+n,cmp1);
    for(int i = 0; i < n-1; i ++) {
        nod[i].k = (p[i+1].y-p[i].y)/(p[i+1].x-p[i].x);
        nod[i].id1 = p[i].id;
        nod[i].id2 = p[i+1].id;
    }
    sort(nod,nod+n-1,cmp2);
    cout << nod[0].id1 << ' ' << nod[0].id2 << endl;
    return 0;
}
