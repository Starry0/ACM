#include <bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
    int n,a,b[5];
    while(cin>>n){
        for(int i = 0; i < n; i++){
            cin >>a;
            s.insert(a);
        }
        if(s.size()<=2){
            cout << "jxust\n";
        }
        else if(s.size()==3){
            set<int>::iterator it = s.begin();
            int i = 0;
            for(;it!=s.end();++it){
                b[i++] = *it;
            }
            if((b[1] - b[0]) == (b[2] - b[1])){
                cout << "jxust\n";
            }
            else cout << "ecjtujxnu\n";
        }
        else cout << "ecjtujxnu\n";
        s.clear();
    }
    return 0;
}
