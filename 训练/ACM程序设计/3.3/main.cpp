/**************************
  1到n!的和
**************************/
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream cin("in.txt");
    int n,sum,p;
    while(cin>>n){
        sum = 0;
        p = 1;
        for(int i = 1;i <= n; i++){
            p*=i;
            sum+=sum+p;
        }
        cout<<sum<<endl;
    }
    return 0;
}
