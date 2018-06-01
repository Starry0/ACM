#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 200002
using namespace std;

int a[MAX],ans[MAX];
vector<int> v,num;

int main()
{
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        v.clear();
        num.clear();
        for(int i=n-1;i>=0;i--){
            if(v.size()==0 || v.back()>=a[i]){
                v.push_back(a[i]); num.push_back(i);
                ans[i]=-1;
            }else{
                int j = (lower_bound(v.rbegin(),v.rend(),a[i]) - v.rbegin());
                j = (int)v.size() - j - 1;
                ans[i] = num[j+1] - i - 1;
            }
        }
        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
