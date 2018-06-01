#include <bits/stdc++.h>
using namespace std;
struct Nod {
    string name;
    string s;
    int ans;
}nod[110];
bool cmp(Nod &a, Nod &b) {
    if(a.ans != b.ans) return a.ans > b.ans;
    else return a.name < b.name;
}
int main( ){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < m; i ++) {
        cin >> nod[i].name;
        cin >> nod[i].s;
        nod[i].ans = 0;
        for(int j = 0; j < s.length(); j ++) {
            if(s[j] == nod[i].s[j]) nod[i].ans ++;
        }
    }
    sort(nod,nod+m,cmp);
    cout << nod[0].name << endl;
    printf("%.2lf\n",100.0*nod[0].ans/s.length());
    return 0;
}
