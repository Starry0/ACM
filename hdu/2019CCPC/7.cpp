//
// Created by starry on 2019/8/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
vector<vector<int> > vs[11];

void init() {
    for(int i = 2; i <= 10; i ++) {
        int len = vs[i-1].size();
        vector<int> tmp, tmp2;
        for(int j = 0; j < len; j ++) {
            tmp.clear();
            for(auto x : vs[i-1][j]) tmp.push_back(x);
            for(auto x : vs[i-1][j]) tmp.push_back(x);
            vs[i].push_back(tmp);
        }
        for(int j = len/2; j < len; j ++) {
            tmp.clear();
            for(int k = 0; k < len/2; k ++) tmp.push_back(vs[i-1][j][k]);
            for(int k = 0; k < len/2; k ++) tmp.push_back(vs[i-1][j][k]);
            for(int k = len/2; k < len; k ++) tmp.push_back(vs[i-1][j][k]);
            for(int k = len/2; k < len; k ++) tmp.push_back(vs[i-1][j][k]);
            vs[i].push_back(tmp);
        }
        for(int j = len/2; j < len; j ++) {
            tmp.clear();
            for(int k = len/2; k < len; k ++) tmp.push_back(vs[i-1][j][k]);
            for(int k = 0; k < len/2; k ++) tmp.push_back(vs[i-1][j][k]);
            for(int k = 0; k < len/2; k ++) tmp.push_back(vs[i-1][j][k]);
            for(int k = len/2; k < len; k ++) tmp.push_back(vs[i-1][j][k]);
            vs[i].push_back(tmp);
        }
    }
}


int main() {
    ll t,k;
    int a[] = {0, 0, 1, 0};
    vector<int> tmp1(a,a+2);
    vector<int> tmp2(a+2,a+4);
    vs[1].push_back(tmp1);
    vs[1].push_back(tmp2);
    init();
    cin >> t;
    while(t--) {
        cin >> k;
        for(int i = 0; i < (1<<k); i ++) {
            for(int j = 0; j < (1<<k); j ++) {
                printf("%c",vs[k][i][j]?'P':'C');
            }
            printf("\n");
        }
    }


    return 0;
}