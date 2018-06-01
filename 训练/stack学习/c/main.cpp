#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
string a,b;
int res[100100];
int main(){
    int n;
    while( ~scanf("%d" ,&n) ){
        stack<char> s;
        cin >> a >> b;
        int j = 0, i = 0, k = 0;
        while( i <= n ){
            if( s.empty() ){
                s.push(a[i++]);
                res[k++] = 0;
            }
            if( !s.empty() && s.top() != b[j]){
                s.push(a[i++]);
                res[k++] = 0;
            }
            if( !s.empty() && s.top() == b[j]){
                s.pop();
                res[k++] = 1;
                j++;
            }
        }
        //cout << a[1] << a[2] <<endl;
      //  cout << k << endl;
        if( !s.empty()){
            cout << "No.\n";
        }
        else{
            cout << "Yes.\n";
            for(int i = 0; i < 2*n; i++){
                if( res[i] == 0){
                    cout << "in\n";
                }
                else{
                    cout << "out\n";
                }
            }
        }
        cout << "FINISH\n";
    }
    return 0;
}
