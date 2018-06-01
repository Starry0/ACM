#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
using namespace std;
set<double> st;
int main() {
    int n, m, a, b, cnt = 0;
    cin >> m >> n >> a >> b;
    for(int i = a; i < n+a; i ++) {
        for(int j = b; j < m+b; j ++) {
            st.insert(1.0*j*log2(1.0*i));
        }
    }    
    printf("%d\n",(int)st.size());
    return 0;
}
