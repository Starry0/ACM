#include<iostream>
#include<cmath>
using namespace std;
int pdss(int n){
	int m=0;
	if(n==1||n==2)
		m=1;
	else {for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)m=1;
		break;}}
		return m;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a%b==0)cout<<"Yes";
		else if(pdss(b))cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}cout<<endl;
	return 0;
}
