#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		int h1,h2,m2,m1,s1,s2;
		cin >> h1>>m1>>s1>>h2>>m2>>s2;
		int ans1 = h1*3600+m1*60+s1;
		int ans2 = h2*3600+m2*60+s2;
		if(ans1 > ans2){
			printf("Player2\n");
		}else if(ans1 == ans2){
			printf("Tie\n");
		}else if(ans1 < ans2){
			printf("Player1\n");
		}
	}
	return 0;
}