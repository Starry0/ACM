#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5+7;
int a[maxn], b[maxn];
int query(int *arr, int l, int r, int key){
    while(l <= r){
        int mid = (l + r) >> 1;
        if(arr[mid] == key) return mid;
        if(arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int main()
{
    int n, m, k;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)scanf("%d",&a[i]);
    for(int i = 0; i < m; i++)scanf("%d",&b[i]);
    cin >> k;
    sort(a, a + n);sort(b, b + m);
    int q;
    while(k--){
        cin >> q;
        int flag = 1;
        for(int i = 0; i < n; i++){
            int y = q - a[i];
            //cout << y << endl;
            if(y > 0){
                int pos = query(b, 0, m, y);
                if(pos != -1){
                    cout << "Yes" << endl;
                    flag = 0;
                    break;
                }
            }

        }
        if(flag == 1){
            cout << "No" << endl;
        }
    }
    return 0;
}
