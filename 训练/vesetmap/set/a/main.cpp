#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
const int maxn = 1e5+10;
int a[maxn];
set<int>s;
int main()
{
    int n, m;
    int c;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
       scanf("%d",&a[i]);
    }
    set<int>::iterator it;
    for(int i = 0; i < m; i++){
        scanf("%d",&c);
        s.insert(c);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        scanf("%d",&c);
        for(int i = 0; i < n; i++){
            int d = c - a[i];
            it = s.find(d);
            if(it != s.end()){
                printf("Yes\n");
                break;
            }
        }
        if(it == s.end()){
            cout << "No\n";
        }
    }
    return 0;
}
