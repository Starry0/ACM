#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr(int *ar, int l, int r, int key){
    while(l <= r){
        int mid = (l + r) /2;
        if(ar[mid] <= key) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int main()
{
    int a[] = {1,2,3,4,4,5,6,7,7,8};
    int key = 5;
    cout << arr(a, 0, 9, key) << endl;
    int pos = upper_bound(a, a+10, 6) - a;
    cout << pos << endl;
    pos = lower_bound(a, a + 10, 6) - a;
    cout << pos << endl;
    return 0;
}
