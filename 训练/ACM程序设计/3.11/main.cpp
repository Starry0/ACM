/***********************************
列出完数
“完数”是指一个数恰好等于它的所有不同因子之和。
************************************/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    ifstream cin("in.txt");
    vector<int>a;
    for(int i=2;i<10000;i=i+2){
        int sum = 1;
        for(int j=2;j<=i/2;j++){
            if(i%j==0)sum=sum+j;
        }
        if(sum==i)a.push_back(i);
    }
    int n;
    while(cin>>n){
        cout<<n<<":";
        for(int i=0;i<a.size();i++){
            if(a[i]<=n)cout<<" "<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
