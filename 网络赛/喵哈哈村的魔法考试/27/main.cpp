#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e5+10;
int a[maxn],value[110];
int main()
{
    int n, m;
    while(cin >> n >> m){
        memset(value, 0, sizeof(value));
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            value[a[i]]++;
        }
        int x,y;
        for(int i =0; i < m; i++){
            //scanf("%d",&x);
            cin >> x;
            if(x == 1){
                //scanf("%d%d",&x,&y);
                cin >> x >> y;
                value[a[x]]--;
                a[x] = y;
                value[a[x]]++;
            }
            else{
                int num = 2;
                for(int i = 100; i >= 1; i--){
                    if(value[i] >= num){
                        cout<< i <<endl;
                        break;
                    }
                    else{
                        num -= value[i];
                    }
                }
            }
        }
    }
    return 0;
}
