#include <bits/stdc++.h>
using namespace std;
map<string,int>m;
int main(){
    int n;
    string s;
    m["bowl"]++;m["knife"]++;
    m["fork"]++;m["chopsticks"]++;
    while(~scanf("%d",&n)){
        int k = 1;
        for(int i = 1; i <= n; i++){
            cin>>s;
            if(m.count(s)){
              if(k){
                  cout<<s;
                  k = 0;
              }
              else cout<<" "<<s;
            }
        }
        cout<<endl;
    }
}
