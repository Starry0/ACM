#include <iostream>
#include <cstdio>
#include <cmath>
//const int pi = 3.1415926535;
using namespace std;
int main(){
  int n;
  cin>>n;
  double x;
  while(n--){
    cin>>x;
    printf("%.6f\n",M_PI*x*x);
  }
  return 0;
}
