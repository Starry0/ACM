#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int  is[maxn];
bool solve(int x, int y, int len)
{
      int i;
      is[0]=x;
      is[1]=y;
      for(i=2; i<=len+1; i++){
            if(is[i-1]){
                if(s[i-1]=='o')
                    is[i]=is[i-2];
                else
                    is[i]=!is[i-2];
            }
            else{  //前面的人说了假话
                if(s[i-1]=='o')
                    is[i]=!is[i-2];
                else
                    is[i]=is[i-2];
            }
      }
      /* for(i=0; i<len+2; i++)
       {
          printf(is[i]?"S":"W");
       }
       printf("\n");
       */
      if(is[len]== is[0] && is[len+1]==is[1]){
            for(i=0; i<len; i++){
                printf(is[i]?"S":"W");
            }
            printf("\n");
            return 1;
      }
      return 0;
}

int main()
{
   int n;
   scanf("%d", &n);
   int i;
   scanf("%s", s);
   int len=strlen(s);
   s[len]=s[0];
   s[len+1]=s[1];
   s[len+2]='\0';
   int j;
   for(i=0; i<2; i++)
   {
     for(j=0; j<2; j++)
     {
    if(solve(i, j, len))return 0;
     }
   }
   printf("-1\n");
}
