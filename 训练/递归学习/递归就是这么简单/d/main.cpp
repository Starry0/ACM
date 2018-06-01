#include <iostream>
#define ll long long
using namespace std;
ll arr[55];
int main(){
    int n;
    arr[1] = 1;arr[2] = 2;
    for(int i = 3; i < 52; i ++)
        arr[i] = arr[i-1] + arr[i-2];
    cin >> n;
    int a,b;
    while(n--){
        cin >> a >> b;
        cout << arr[b-a] << endl;
    }
    return 0;
}
