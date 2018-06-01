//一直答案错误
// #include <iostream>
// #include <string.h>
// #include <algorithm>
// #include <stdio.h>
// #include <vector>
// using namespace std;
// const int N = 550;
// double EPS = 1e-10;
// int n, m, ans, cnt;
// // double add(double a,double b) {
// //     if(abs(a+b) < EPS * (abs(a) + abs(b))) return 0;
// //     return a + b;
// // }
// struct Point{
//     int x, y;
//     Point(){}
//     Point(int x, int y) :x(x), y(y) {}
//     Point operator + (Point p) {
//         return Point(x + p.x, y + p.y);
//     }
//     Point operator - (Point p) {
//         return Point(x - p.x, y - p.y);
//     }
//     Point operator * (int d) {
//         return Point(x*d, y*d);
//     }
//     int dot(Point p) {    //内积
//         return x * p.x + y * p.y;
//     }
//     int det(Point p) {    //外积
//         return x * p.y - y * p.x;
//     }
// };
// Point qs[N], qu[N];
// bool vis[N];
// vector<Point> ps;
// bool cmp(Point x, Point y) {
//     if(x.x != y.x) return x.x < y.x;
//     else return x.y < y.y;
// }
// vector<Point> convex_hull(Point *ps, int n) {
//     sort(ps, ps+n, cmp);
//     int k = 0;
//     vector<Point> qs(n*2);
//     for(int i = 0; i < n; i ++) {   //下侧
//         if(vis[i])continue;
//         while(k > 1 && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
//         qs[k++] = ps[i];
//     }
//     for(int i = n-2, t = k; i >= 0; i --) { //上侧
//         if(vis[i])continue;
//         while(k > t && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
//         qs[k++] = ps[i];
//     }
//     cnt = k-1;
//     qs.resize(k-1);
//     return qs;
// }
// bool check() {
//     for(int i = 0; i < n; i ++) {
//         if(m - ans == 1) {
//             if(qs[i].x != ps[0].x || qs[i].y != ps[0].y) return false;
//         } else if(m - ans == 2){
//             if((qs[i] - ps[0]).det(ps[1] - qs[i]) !=  0) return false;
//         } else {
//             for(int j = 0; j < cnt; j ++) {
//                 if((qs[i] - ps[j]).det(ps[(j+1)%cnt] - qs[i]) > 0) {
//                     // printf("%d %d\n",(qs[i] - ps[j]).x,(qs[i] - ps[j]).y);
//                     // printf("%d %d\n",(qs[i] - ps[j]).x,(qs[i] - ps[j]).y);
//                     // printf("%d ++\n",(qs[i] - ps[j]).det(ps[(j+1)%cnt] - qs[i]) );
//                     // printf("%d  %d\n",i,j);
//                     return false;
//                 }
//             }
//         }
//     }
//     return true;
// }
// int main() {
//     while(scanf("%d",&n) != EOF) {
//         memset(vis, false, sizeof(vis));
//         ans = 0;
//         for(int i = 0; i < n; i ++) {
//             scanf("%d %d", &qs[i].x, &qs[i].y);
//         }
//         scanf("%d", &m);
//         for(int i = 0; i < m; i ++) {
//             scanf("%d %d", &qu[i].x, &qu[i].y);
//         }
//         ps = convex_hull(qu, m);
//         // for(int i = 0; i < ps.size(); i ++) {
//         //     printf("%d %d\n",ps[i].x, ps[i].y);
//         // }
//         if(!check()) {
//             printf("ToT\n");
//             continue;
//         }
//         for(int i = 0; i < m; i ++) {
//             if(m - ans == 1)break;
//             vis[i] = true;
//             ps.clear();
//             ps = convex_hull(qu, m);
//             if(check()) {
//                 ans ++;
//                 continue;
//             }
//             else vis[i] = false;
//         }
//         printf("%d\n",ans);
//         ps.clear();
//     }
//     return 0;
// }

//正解
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 550;
struct Point {
    int x, y;
};
int n, m, G[N][N];
Point a[N], b[N];
int mymin (int x,int y){return x<y?x:y;}
bool check(Point a, Point b, Point c) {
    if(a.x > b.x && a.x > c.x) return true;
    if(a.x < b.x && a.x < c.x) return true;
    if(a.y < b.y && a.y < c.y) return true;
    if(a.y > b.y && a.y > c.y) return true;
    return false;
}
double fun(Point a, Point b, Point c) {
    double x1 = a.x - c.x, y1 = a.y - c.y;
    double x2 = b.x - c.x, y2 = b.y - c.y;
    return x1 * y2 - x2 * y1;
}
int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; i ++) {
            scanf("%d %d", &a[i].x, &a[i].y);
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i ++) {
            scanf("%d %d", &b[i].x, &b[i].y);
        }
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= m; j ++) {
                G[i][j] = INF;
            }
        }
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= m; j ++) {
                bool flag = true;
                for(int k = 1; k <= n; k ++) {
                    if(fun(a[k], b[j], b[i]) < 0) flag = false;
                    if(fun(a[k], b[j], b[i]) == 0 && check(a[k], b[j], b[i])) flag = false;
                    if(!flag) break;
                }
                if(flag) G[i][j] = 1;
            }
        }
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(G[j][i] == INF) continue;
                for(int k = 1; k <= m; k ++) {
                    G[j][k] = mymin(G[j][k], G[j][i] + G[i][k]);
                }
            }
        }
        int ans = INF;
        for(int i = 1; i <= m; i ++) {
            ans = mymin(ans, G[i][i]);
        }
        if(ans > m) printf("ToT\n");
        else printf("%d\n",m - ans);
    }
    return 0;
}
