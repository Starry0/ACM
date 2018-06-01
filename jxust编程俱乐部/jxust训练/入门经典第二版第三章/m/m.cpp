#include <bits/stdc++.h>
using namespace std;
map<int,int>m;
vector<int>v;
int main(){
    int a,b,c,temp,nb,ntemp;
    while(scanf("%d%d",&a,&b)!=EOF){
        int ans = 0;
        int A=a,B=b;
        c = a/b;
        a = a - c*b;
        m[a]++;
        v.push_back(c);
        while(a){
            temp = b/a;
            if(m[temp])
                break;
            else m[temp]++;
            ntemp = log10(temp)+1;
            nb = log10(b)+1;
            for(int i = 0;i<(nb-ntemp-1);i++){
                v.push_back(0);
                ans++;
            }
            v.push_back(temp);
            ans += ntemp;
            a = b - a*temp;
      }
      vector<int>::iterator it = v.begin();
      printf("%d/%d = %d.(",A,B,(*it));
      ++it;
      int k = 0;
      for(;it!=v.end();++it){
          printf("%d",(*it));
          k++;
          if(k==50){
            printf("...");
          }
      }
      printf(")\n");
      printf("   %d = number of digits in repeating cycle\n",k);
      m.clear();v.clear();
    }
    return 0;
}
