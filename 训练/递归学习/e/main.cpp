/*#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
map<int,string> mp;
int a[6] = {0, 1, 2, 3, 4};
static int ans = 1;
void f(int *arr, int k, int m){
    if(k == m){
        int b[3];
        b[0] = arr[2];b[1] = arr[3]; b[2] = arr[4];
        sort(b,b+3);
        cout << ans++;
        for(int i = 0; i < m; i++){
            cout << '\t' << mp[arr[i]];
        }
        cout << '\t' << mp[b[0]];
        printf("\n");

        cout << ans++;
        for(int i = 0; i < m; i++){
            cout << '\t' << mp[arr[i]];
        }
        cout << '\t' << mp[b[1]];
        printf("\n");

        cout << ans++;
        for(int i = 0; i < m; i++){
            cout << '\t' << mp[arr[i]];
        }
        cout << '\t' << mp[b[2]];
        printf("\n");

    }
    else{
        for(int i = k; i < 5; i++){
            swap(arr[i],arr[k]);
            f(arr,k+1,m);
            swap(arr[i],arr[k]);
        }
    }
}
int main(){
    mp[0] = "red";mp[1] = "yellow"; mp[2] = "blue";
    mp[3] = "white"; mp[4] = "black";
    f(a, 0, 2);
    return 0;
}
*/


#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
map<int,string> mp;
int a[6] = {0, 1, 2, 3, 4};
int main(){
    mp[0] = "red";mp[1] = "yellow"; mp[2] = "blue";
    mp[3] = "white"; mp[4] = "black";
    int ans  = 1;
    for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 5; j ++){
            for(int k = 0; k < 5; k ++){
                if(i!=j&&i!=k&&j!=k){
                    printf("%d",ans++);
                    cout << '\t' << mp[i] << '\t' << mp[j] << '\t' << mp[k] << endl;
                }
            }
        }
    }
    return 0;
}
