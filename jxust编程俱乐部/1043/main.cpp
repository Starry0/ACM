#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double a,b,c,x1,x2;
int bigger_than_zero()
{
    x1=(-b+sqrt(b*b-4*a*c))/(2*a);x2=(-b-sqrt(b*b-4*a*c))/(2*a);
    cout<<setiosflags(ios::fixed)<<setprecision(3);
    cout<<"x1="<<x1<<" "<<"x2="<<x2;
}
int equal_to_zero()
{
    x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    cout<<setiosflags(ios::fixed)<<setprecision(3);
    cout<<"x1="<<x1<<" "<<"x2="<<x1;
}
int smaller_than_zero()
{
    x1=sqrt(4*a*c-b*b)/(2*a);x2=-b/(2*a);
    cout<<setiosflags(ios::fixed)<<setprecision(3);
    cout<<"x1="<<x2<<"+"<<x1<<"i "<<"x2="<<x2<<"-"<<x1<<"i";
}
int main()
{
   cin>>a>>b>>c;
   if(b*b-4*a*c>0)bigger_than_zero();
   else if(b*b-4*a*c==0)equal_to_zero();
   else smaller_than_zero();
   cout<<endl;
   return 0;
}
