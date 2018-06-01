#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

float a[110];
int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    float ave=0;
    for(int i=0;i<n;i++)
      cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n-1;i++)
      ave =ave + a[i]*1.0/(n-2);
    printf("%.2f\n",ave);
  }
  return 0;
}
