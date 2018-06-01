#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
#define lowvit(x) x&(-x)
#define N 50010
#define M 210
using namespace std;
char str[M];
struct Nod {
    int num;
    Nod * next[11];
    Nod(){
        for(int i = 0; i < 10; i ++)
            next[i] = NULL;
        num = 0;
    }
};
int len;
void mkTree(Nod *p,char *str) {
    for(int i = 0; i < len; i ++) {
        int x = str[i] - '0';
        if(p->next[x] == NULL) {
            p->next[x] = new Nod;
        }
        p = p->next[x];
        p->num++;
    }
}
int MAX = -1;
void dfs(Nod *p, int x) {
    for(int i = 0; i < 10; i ++) {
        if(p->next[i] != NULL) {
            Nod *p1 = p->next[i];
            int ans = p1->num;
            if(MAX < ans*(x+1)) {
                MAX = ans*(x+1);
                // printf("%d %d \n",ans,(x+1));
            }
            dfs(p1,x+1);
        }
    }
    return ;
}
void dele(Nod *p) {
    for(int i = 0; i < 10; i ++) {
        if(p->next[i])
            dele(p->next[i]);
    }
    free(p);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin>>t;
    while(t--) {
        Nod *root = new Nod;
        cin>>n;
        for(int i = 0; i < n; i ++) {
            cin>>str;
            len = strlen(str);
            mkTree(root,str);
        }
        MAX = 0;
        dfs(root, 0);
        printf("%d\n",MAX);
        dele(root);
    }
    return 0;
}

//
// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <algorithm>
// #include <string>
// #include <queue>
// #include <vector>
// #include <set>
// #include <map>
// #define ll long long
// #define INF 0x3f3f3f3f
// #define lowvit(x) x&(-x)
// #define N 50000
// #define M 110
// using namespace std;
// int tree[N], sum[N][11], sz = 1, MAX;
// char str[N];
// void mkTree(char *str) {
//     int root = 0, len = strlen(str);
//     for(int i = 0; i < len; i ++) {
//         int x = str[i] - '0';
//         if(!sum[root][x]) sum[root][x] = sz ++;
//         root = sum[root][x];
//         tree[root]++;
//     }
// }
// void dfs(int root, int de) {
//     for(int i = 0; i < 10; i ++) {
//         // printf("%d\n",i);
//         if(sum[root][i]) {
//             int p = sum[root][i];
//             int ans = tree[p]*(de+1);
//             if(ans > MAX) MAX = ans;
//             dfs(p,de+1);
//         }
//     }
//     return;
// }
// int main() {
//     int t, n;
//     ios::sync_with_stdio(false);
//     cin>>t;
//     while(t--) {
//         cin>>n;
//         for(int i = 1; i <= n; i ++) {
//             cin>>str;
//             mkTree(str);
//         }
//         MAX = 0;
//         dfs(0, 0);
//         printf("%d\n",MAX);
//         memset(tree, 0, sizeof(tree));
//         memset(sum, 0, sizeof(sum));
//     }
//     return 0;
// }
