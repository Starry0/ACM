#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <int >v;
int main(){
  int n;
  cin>>n;
  int ans=0;
  for(int i=1;i<=n;i++){
    v.push_back(i);
    n-=i;
  }
  cout<<v.size()<<endl;
  for(int i=0;i<v.size()-1;i++)
    printf("%d ",v[i]);
  cout<<v[v.size()-1]+n<<endl;
  return 0;
}
