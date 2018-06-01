#include <iostream>
#include <map>
using namespace std;
map<int,int> m;
int main()
{
    int n,a;
    while(cin>>n){
        for(int i = 0; i < n; i++){
            cin >> a;
            m[a]++;
        }
        map<int,int>::iterator it = m.begin();
        for(; it != m.end(); it++){
            if((*it).second == 1){
                cout << (*it).first <<endl;
                break;
            }
        }
        m.clear();
    }
    return 0;
}
