#include <iostream>
using namespace std;

int main()
{
	int a,b,c,z;
	cin>>a>>b>>c;
	if(a>b)z=a;
	else z=b;
	if(c>z)z=c;
	cout<<z;
	return 0;
}
