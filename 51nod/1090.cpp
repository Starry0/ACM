// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// using namespace std;
// int a[1010];
// int main() {
//     int n;
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
//     sort(a+1,a+n+1);
//     int ans = 0;
//     for(int i = 1; i <= n; i ++) {
//         for(int j = i+1; j <= n; j ++) {
//             for(int k = j+1; k <= n; k ++) {
//                 if(a[i] + a[j] + a[k] == 0) {
//                     printf("%d %d %d\n",a[i], a[j], a[k]);
//                     ans++;
//                 }
//             }
//         }
//     }
//     if(ans == 0) printf("No Solution\n");
//     return 0;
// }

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
int a[1010];
set<int> st;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), st.insert(a[i]);
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = i+1; j <= n; j ++) {
            int x = 0 - a[i] - a[j];
            if(x > a[j] && st.count(x)) {
                printf("%d %d %d\n",a[i], a[j], x);
                ans++;
            }
        }
    }
    if(ans == 0) printf("No Solution\n");
    return 0;
}
