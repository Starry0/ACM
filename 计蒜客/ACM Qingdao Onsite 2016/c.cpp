#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        double d, l;
        cin >> d >> l;
        if(d <= l)printf("0.000000\n");
        else printf("%.6f\n",log(d/l)+1);
    }
    return 0;
}