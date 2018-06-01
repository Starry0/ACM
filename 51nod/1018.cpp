#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 5e4+10;
int a[N];
void qsort1(int *a, int l, int r){
    if(l < r){
        int key = a[l];
        int low = l;
        int high = r;
        while(low < high){
            while(low < high && a[high] > key){
                high--;
            }
            a[low] = a[high];
            while(low < high && a[low] < key){
                low++;
            }
            a[high] = a[low];
        }
        a[low] = key;
        qsort1(a,l,low-1);
        qsort1(a,low+1,r);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
    qsort1(a,0,n-1);
    for(int i = 0; i < n; i ++) printf("%d\n",a[i]);
    return 0;
}
