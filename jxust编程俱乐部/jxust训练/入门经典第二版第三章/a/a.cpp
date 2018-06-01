/*
"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"

*/


#include <bits/stdc++.h>
using namespace std;
int main(){
  char c;
  int a = 0;
  while((c=getchar())!=EOF){
    if(c=='"'){
      a++;
      if(a%2!=0)
        printf("``");
      else printf("''");
    }
    else printf("%c",c);
  }
  return 0;
}
