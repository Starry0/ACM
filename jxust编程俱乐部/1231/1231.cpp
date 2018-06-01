#include <bits/stdc++.h>
using namespace std;
struct DATE{
  float a,b,c;
}date[1000];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>date[i].a>>date[i].b>>date[i].c;
    float sum = 0;
    for(int i=0;i<n;i++){
        if(date[i].b>=60){
          sum += date[i].a;
        }
        else if(date[i].c>=60){
          sum += date[i].a;
        }
    }
    cout<<sum<<endl;
}
