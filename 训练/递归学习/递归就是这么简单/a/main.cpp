#include <iostream>
using namespace std;

int f(int x){
    return (x<4)?x:(f(x-1)+f(x-3));
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        cout << f(n)<< endl;
    }
    return 0;
}
