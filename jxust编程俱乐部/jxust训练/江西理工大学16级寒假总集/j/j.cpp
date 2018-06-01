#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int sx,sy,tx,ty;
  cin>>sx>>sy>>tx>>ty;
  for(int i=0;i<ty-sy;i++)
    printf("U");
  for(int i=0;i<tx-sx;i++)
    printf("R");
  for(int i=0;i<ty-sy;i++)
    printf("D");
  for(int i=0;i<=tx-sx;i++)
    printf("L");
  for(int i=0;i<=ty-sy;i++)
    printf("U");
  for(int i=0;i<=tx-sx;i++)
    printf("R");
  printf("DR");
  for(int i=0;i<=ty-sy;i++)
    printf("D");
  for(int i=0;i<=tx-sx;i++)
    printf("L");
  printf("U");
  return 0;
}
