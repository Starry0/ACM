#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

stack<int>s;

int main(){
    int t;
    string ss;
    cin >> t;
    while(t--){
        cin >> ss;
        int maxn = -1;
        s.push(-1);
        s.push(0);
        for( int i = 1, len = ss.length(); i <len ; i++){
            if( ss[s.top()] == '(' && ss[i] == ')'){
                s.pop();
            }
            else{
                s.push(i);
            }
        }
        s.push(ss.length());
        int flag = s.top();
        s.pop();
        while( !s.empty()){
            int tmp = s.top();
            maxn = max( maxn, abs(tmp - flag));
            flag = s.top();
            s.pop();
        }
        cout << maxn - 1 << endl;
    }
    return 0;
}
