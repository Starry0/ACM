/************************
        等比数列
  已知q与n，求等比数列之和：1+q+q2+q3+q4+...+qn。
************************/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(){
    ifstream cin("in.txt");
    cout.precision(3);
    int n;
    double q,sum;
    while(cin>>n>>q){
      if(q==1) sum = 1 + n;
      else
          sum = (1 - pow(q,n+1))/(1-q);
      cout<<fixed<<sum<<endl;
    }
    return 0;
}
