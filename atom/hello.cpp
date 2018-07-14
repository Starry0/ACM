#include<iostream>
#include<algorithm>
using namespace std;
struct node{
  int a,b,d;
};
int main(){
    int a[12];
    for(int i=1;i<=10;i++){
      cin>>a[i];
    }
    for(int i=1;i<=9;i++){
      for(int j=1;j<=10-i;j++){
        if(a[j]>a[j+1])
        swap(a[j],a[j+1]);
      }
    }
    for(int i=1;i<=10;i++)
    cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
