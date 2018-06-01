#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
const int N = 300;
char str[N];
int main(){
    cin >> str;
    stack<int> st;
    for(int i = 0; str[i]; i ++) {
        if(str[i] == '(') st.push(1);
        else if(str[i] == ')') {
            if(st.empty()) return 0*printf("NO\n");
            st.pop();
        }
    }
    if(st.empty()) printf("YES\n");
    else printf("NO\n");
	return 0;
}
