/**************************************
insert(),iterator, clear(),sort(),reverse(),Info,erase();

**************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
vector<int> v;
int main(){
    int a;
    for(int i = 0; i < 10; i ++){
        cin >> a;
        v.push_back(a);
    }
    cout << v.size() << endl;
    for(int i = 0; i < 10; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    vector<int>::iterator it = v.begin();
    v.insert(it,11);
    reverse(v.begin(), v.end());
    for(;it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    cout << v[0] << endl;
    v.clear();
    cout << v.size() << endl;

    return 0;
}
