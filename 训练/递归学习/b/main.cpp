#include <iostream>
using namespace std;

int f(int x){
    if(x == 0){
        return 0;
    }
    else if(x == 1){
      return 1;
    }
    else return f(x-1)+f(x-2);
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << f(i) << endl;
    }
    return 0;
}
