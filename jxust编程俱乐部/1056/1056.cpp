#include <iostream>
#include <cstdio>
#define MAXN(a,b,c) (a)>(b)&&(a)>(c)?a:((b)>(c)?(b):(c))
using namespace std;

float f(float *a){
  float m;
  if(a[0]>a[1])
    m=a[0];
  else m=a[1];
  if(m>a[2])
    return m;
  else return a[2];
}
int main(){
  float a[3];
  cin>>a[0]>>a[1]>>a[2];
  printf("%.3f\n",f(a));
  printf("%.3f\n",MAXN(a[0],a[1],a[2]));
  return 0;
}
