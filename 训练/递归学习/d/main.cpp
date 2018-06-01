#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
void f(int arr[], int k, int m){
    if(k == m){
        for(int i = 0; i <= m; i++){
            printf("%4d",arr[i]);
        }
        printf("\n");
    }
    else{
        for(int i = k; i <= m; i++){
            swap(arr[i], arr[k]);
            f(arr, k+1, m);
            swap(arr[i], arr[k]);
        }
    }
}
int main(){
    int n;
    cin >> n;
    int a[11];
    for(int i = 0; i < n; i++)
        a[i] = i+1;
    f(a,0,n-1);
    return 0;
}
