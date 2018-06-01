#include <bits/stdc++.h>
using namespace std;
int a[7], n, x_1, x_2, y_1, y_2;
int x[7], y[7];
double r[7];
double max(double x, double y) {
    return x>y?x:y;
}
double min(double x, double y) {
    return x<y?x:y;
}
double dis(double xx, double yy) {
	return min(min(fabs(xx-x_1),fabs(xx-x_2)),min(fabs(yy-y_1),fabs(yy-y_2)));
}
double dist(double xx, double yy, double x1, double y1) {
	return sqrt((xx-x1)*(xx-x1)+(yy-y1)*(yy-y1));
}
int main() {
	double pi = acos(-1);
	cin >> n;
	cin >> x_1 >> y_1 >> x_2 >> y_2;
	for(int i = 1; i <= n; i ++) cin >> x[i] >> y[i];
	double MAX = 0;
	for(int i = 1; i <= n; i ++) a[i] = i;
	do{
		for(int i = 1; i <= n; i ++) {
			r[i] = dis(x[a[i]],y[a[i]]);
			for(int j = 1; j < i; j ++) {
				double t = dist(x[a[i]],y[a[i]],x[a[j]],y[a[j]]);
                r[i] = min(r[i],max(0,t-r[j]));
			}
		}
		double t = 0;
		for(int i = 1; i <= n; i ++) {
			t += r[i]*r[i]*pi;
		}
        MAX = max(MAX,t);
	}while(next_permutation(a+1,a+n+1));
    printf("%.0lf\n",fabs(x_1-x_2)*fabs(y_1-y_2)-MAX);
	return 0;
}
