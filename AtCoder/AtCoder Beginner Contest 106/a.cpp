#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	printf("%d\n",a*b-(a+b-1));
	return 0;
}