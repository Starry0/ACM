#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct Nod {
	char str[10];
	double c, m, e, p, ch;
	double arg;
}nod[11];
bool cmp(Nod a, Nod b) {
	return a.arg > b.arg;
}
double a[6];
int main(){
	for(int i = 0; i < 10; i ++) {
		cin >> nod[i].str >> nod[i].c >> nod[i].m >> nod[i].e >> nod[i].p >> nod[i].ch;
		//scanf("%s %lf %lf %lf %lf %lf", nod[i].str,nod[i].c,nod[i].m,nod[i].e,nod[i].p,nod[i].ch);
		nod[i].arg = (nod[i].c + nod[i].m + nod[i].e + nod[i].p + nod[i].ch) / 5.0;
		a[0] += nod[i].c; a[1] += nod[i].m;
		a[2] += nod[i].e; a[3] += nod[i].p;
		a[4] += nod[i].ch;
	}
	for(int i = 0; i < 10; i ++) {
		printf("%s %.3lf\n",nod[i].str, nod[i].arg);
	}
	printf("chinese %.3lf\n", a[0] / 10);
	printf("math %.3lf\n", a[1] / 10);
	printf("english %.3lf\n", a[2] / 10);
	printf("physical %.3lf\n", a[3] / 10);
	printf("chemistry %.3lf\n", a[4] / 10);
	sort(nod, nod+10, cmp);
	double MAX = 0;
	int cnt = 0;
	for(int i = 0; i < 5; i ++) {
		if(MAX < a[i]) {
			MAX = a[i];
			cnt = i;
		}
	}
	printf("%s\n",nod[0].str);
	if(cnt == 0) printf("chinese\n");
	else if(cnt == 1) printf("math\n");
	else if(cnt == 2) printf("english\n");
	else if(cnt == 3) printf("physical\n");
	else if(cnt == 4) printf("chemistry\n"); 
	return 0;
}