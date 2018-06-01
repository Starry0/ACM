#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
const int N = 100010;
stack<int> st;
int main() {
    int n, x, y;
    scanf("%d", &n);
    int ans = n;
    for(int i = 0; i < n; i ++) {
        scanf("%d %d", &x, &y);
        if(y == 1) st.push(x);
        else {
            while(!st.empty()) {
                if(st.top() > x) {
                    ans--;break;
                }else if(st.top() < x) {
                    ans--;st.pop();
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
