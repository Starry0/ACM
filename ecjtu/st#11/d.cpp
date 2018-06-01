#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
const double ef = 1e-9;
const int MAX = 11000;
vector<pair<double,double> >vs[MAX];
int main() {
    int t, n, m;
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        int b = 100000;
        for(int i = 1; i <= n; i ++) {
            cin >> m;
            int MM = -1;
            for(int j = 1; j <= m; j ++) {
                double x, y;
                cin >> x >> y;
                if(x > MM) MM = x;
                vs[i].push_back(make_pair(x,y));
            }
            if(MM < b) b = MM;
        }
        double p = 0.0;
        for(int i = 1; i <= n; i ++) {
            double pp = 100000;
            for(int j = 0; j < vs[i].size(); j ++) {
                if(vs[i][j].first >= b){
                    if(pp > vs[i][j].second) pp = vs[i][j].second;
                }
            }
            // cout << pp << endl;
            p += pp;
        }
        printf("%.3f\n",b/p);
        //cout << b<< ' ' << p << endl;
        for(int i = 1; i <= n; i ++) vs[i].clear();
    }
    return 0;
}
