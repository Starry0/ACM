#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int prime(int);
    int n;
    cin>>n;
    if(prime(n))
    cout<<"prinme"<<endl;
    else cout<<"not prime"<<endl;
    return 0;
}
int prime(int n)
{
    int flag=1,i;
    for(i=2;i<sqrt(n);i++)
        if(n%i==0)
        flag=0;
    return(flag);
}
/*using namespace std;
int f(int x)
{
	int a,z=1;
	for (a=2;a<=sqrt(x);a++)
	{
		if (x%a==0)
		z=0;
	}
	return z;
}
int main()
{
	int a,n;
	cin>>n;
	a=f(n);
	if (a)
	cout<<"prime";
	else cout<<"not prime";
	return 0;
}*/
