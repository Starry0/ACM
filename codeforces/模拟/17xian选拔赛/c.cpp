#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 110;
double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main() {
	int t, k = 1;
	scanf("%d", &t);
	double pi = acos(-1);
	while(t--) {
		double gx, gy, gr, wx, wy, wr;
		cin >> gx >> gy >> gr;
		cin >> wx >> wy >> wr;
		double dd = dis(gx, gy, wx, wy);
		if(dd >= (gr+wr)) {
			printf("Case #%d: %.8lf\n",k++,pi*gr*gr);
		} else if(dd + wr <= gr ){
			printf("Case #%d: %.8lf\n",k++,pi*(gr*gr - wr*wr));
		} else if(dd + gr <= wr) {
			printf("Case #%d: 0.00000000\n",k++);
		} else {
			double a1 = acos((gr*gr + dd*dd - wr*wr) / (2*gr*dd));
			double a2 = acos((wr*wr + dd*dd - gr*gr) / (2*wr*dd));
			double area1 = (sin(a1*2)*gr*gr+sin(a2*2)*wr*wr)/2;
			double area2 = gr*gr*a1 + wr*wr*a2;
			printf("Case #%d: %.8lf\n",k++,pi*gr*gr-(area2-area1));
		}
	}
	return 0;
}