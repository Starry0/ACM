#include <bits/stdc++.h>
using namespace std;
char a[] = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main(){
  int i,c;
  while((c=getchar())!=EOF){
    for(i = 1;a[i]&&a[i] != c;i++);
    if(a[i])
      putchar(a[i-1]);
      else putchar(c);
  }
  return 0;
}
