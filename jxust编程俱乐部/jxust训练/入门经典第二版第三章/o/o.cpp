#include <bits/stdc++.h>
using namespace std;
struct DATE{
  int x;
  int y;
}M[6];
bool cmp(DATE a,DATE b){
  if(a.x!=b.x) return a.x>b.x;
  else return a.y>b.y;
}
int main(){
  int a,b,c,d,e,f,g,h,i,j,k,l;
  while(cin>>M[0].x>>M[0].y>>M[1].x>>M[1].y>>M[2].x>>M[2].y>>M[3].x>>M[3].y>>M[4].x>>M[4].y>>M[5].x>>M[5].y){
    for(int i=0;i<6;i++)
      if(M[i].x<M[i].y)
        swap(M[i].x,M[i].y);
    sort(M,M+6,cmp);
    /*for(int i=0;i<6;i++){
      cout<<M[i].x<<' '<<M[i].y<<endl;
    }*/
    if(M[0].x==M[1].x&&M[0].y==M[1].y&&M[2].x==M[3].x&&M[2].y==M[3].y&&M[4].x==M[5].x&&M[4].y==M[5].y){
      if(M[0].x==M[2].x&&M[0].y==M[4].x&&M[2].y==M[4].y)
        cout<<"POSSIBLE"<<endl;
      else cout<<"IMPOSSIBLE"<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
  }
  return 0;
}
