#include <iostream>
#include <cstdio>
using namespace std;
int f(int x){
    int ans = 0;
    if(x==1){
      return 10;
    }
    else{
      ans += f(x-1)+2;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout << f(n) << endl;
    return 0;
}
