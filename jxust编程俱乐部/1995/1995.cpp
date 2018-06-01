#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct DATE{
  string name;
  int score;
  int bscore;
  char bgb;
  char xbs;
  int rw;
  int bouns;
  int idx;
};
bool cmp(DATE a,DATE b){
  if(a.bouns==b.bouns) return a.idx<b.idx;
  return a.bouns>b.bouns;
}
int main(){
  DATE date[110];
  int sum=0,maxn=0,k=0;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>date[i].name>>date[i].score>>date[i].bscore>>date[i].bgb>>date[i].xbs>>date[i].rw;
    date[i].bouns=0;
    date[i].idx=i;
    if(date[i].score>80&&date[i].rw>0)
      date[i].bouns+=8000;
    if(date[i].score>85&&date[i].bscore>80)
      date[i].bouns+=4000;
    if(date[i].score>90)
      date[i].bouns+=2000;
    if(date[i].score>85&&date[i].xbs=='Y')
      date[i].bouns+=1000;
    if(date[i].bscore>80&&date[i].bgb=='Y')
      date[i].bouns+=850;
    /*if(date[i].bouns>maxn){
      maxn=date[i].bouns;
      k=i;
    }*/
    sum+=date[i].bouns;
  }
  sort(date,date+n,cmp);
  cout<<date[0].name<<endl<<date[0].bouns<<endl<<sum<<endl;
  return 0;
}
