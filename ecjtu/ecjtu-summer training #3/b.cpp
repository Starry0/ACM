#include <bits/stdc++.h>
#define ll long long
using namespace std;
double r,R,h,v;
const double ef = 1e-9;
const double PI = acos(-1);
double fun(double xx){
	double RR = xx/h*(R-r)+r;
	return PI*(RR*RR+r*r+RR*r)*xx/3.0;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>r>>R>>h>>v;
		double l = 0, r = 100,mid;
		while(r-l>ef){
			mid = (l+r)/2;
			if(fun(mid) < v) l = mid;
			else r = mid;
		}
		printf("%.6lf\n",mid);
	}
	return 0;
}

/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define mod 1e-8
#define p 3.1415926535897932384626433832795
double r,R,H,V;
int t;
double check(double r,double R,double h,double H)
{
    double x=h/H*(R-r)+r;  
    return (p*(r*r+x*x+r*x)*h)/3.0; 
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&r,&R,&H,&V);
        double lh=0,rh=100,mid;
        while((rh-lh)>mod)
        {
            mid=(lh+rh)/2;
            double xx=check(r,R,mid,H);
            if(xx<V){
                lh=mid;
            }
            else rh=mid;
        }
        printf("%.6lf\n",mid);
    }
    return 0;
}*/