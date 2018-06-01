// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5e4+10;
// struct Nod{
//     int e, w;
// }nod[N];
// int n;
// bool cmp(Nod &a, Nod &b) {
//     return a.w > b.w;
// }
// int main() {
//     cin >> n;
//     set<int> st;
//     for(int i = 0; i < n; i ++)
//         cin >> nod[i].e >> nod[i].w;
//     sort(nod,nod+n,cmp);
//     int ans = 0;
//     for(int i = 0; i < n; i ++) {
//         if(!st.count(nod[i].e)) {
//             ans += nod[i].w;
//             st.insert(nod[i].e);
//         } else {
//             int x = nod[i].e-1;
//             while(x >= 1) {
//                 if(!st.count(x)) {
//                     ans += nod[i].w;
//                     st.insert(x);
//                     break;
//                 }
//                 x--;
//             }
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4+10;
struct Nod{
    int e, w;
}nod[N];
bool cmp(Nod &a, Nod &b) {
    return a.e < b.e;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> nod[i].e >> nod[i].w;
    sort(nod,nod+n,cmp);
    priority_queue<int,vector<int>, greater<int> > que;
    for(int i = 0; i < n; i ++) {
        if(nod[i].e > que.size()) {
            que.push(nod[i].w);
        } else if(nod[i].e == que.size()) {
            if(que.top() < nod[i].w) {
                que.pop();
                que.push(nod[i].w);
            }
        }
    }
    ll ans = 0;
    while(que.size()) {
        ans += 1LL*que.top();
        que.pop();
    }
    cout << ans << endl;
}
