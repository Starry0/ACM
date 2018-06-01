#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(int x, int y){
    return x > y;
}
int main(){
    int n;
    double a[110];
    double sum = 0.0;
    cin >> n;
    for( int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++){
        double q = a[i];
        a[i + 1] = 2.0 * sqrt(a[i] * a[i +1]);
    }
    printf("%.3lf\n", a[n - 1]);
    return 0;
}
