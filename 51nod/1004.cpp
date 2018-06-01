#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
int a[10][5] = {{0},{1},{6, 2, 4, 8, 6}, {1, 3, 9, 7, 1}, {6, 4, 6, 4, 6}, {5}, {6},
                {1, 7, 9, 3, 1}, {6, 8, 4, 2, 6}, {1, 9, 1, 9, 1}};
int main() {
    int n;
    cin >> n;
    int x = n % 10;
    if(x == 0 || x == 6 || x == 1 || x == 5) printf("%d\n",x);
    else printf("%d\n",a[x][n%4]);
    return 0;
}
