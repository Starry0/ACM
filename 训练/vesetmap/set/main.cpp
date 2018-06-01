/*******************************************
insert(),erase(),iterator,begin(),end(),size(),empty(),find();
********************************************/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct Cmp(){
    bool operator () (const int &a, const int &) 
}

set<int> s;
int main(){
    int a;
    for(int i = 0; i < 10; i++){
       cin >> a;
       s.insert(a);
    }
    set<int>::iterator it = s.begin();
    for(; it != s.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
  //  reverse(s.begin(), s.end());
    for(it = s.begin(); it != s.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
