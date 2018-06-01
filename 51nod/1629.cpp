#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
double PI = acos(-1);
int main() {
	//cout << PI << endl;
	int s;
	cin >> s;
	double h = sqrt(2.0*s/PI);
	double r = sqrt(1.0*s*s/(PI*PI*h*h+2*PI*s));
	printf("%.6f\n",PI*r*r*h/3);
	return 0;
}