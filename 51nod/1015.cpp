#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int A[500] = {153, 370, 371, 407, 1634};
int main() {
    int n;
    cin >> n;
    cout << *lower_bound(A,A+5,n) << endl;
    return 0;
}
