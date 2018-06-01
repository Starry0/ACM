#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100005
#define inf 0x7fffffff
#define LL long long
#define uLL unsigned long long
const int mod = 1e9+7;
const LL INF = 9e18;
typedef pair<int, uLL>P;
const double eps = 1e-6;

uLL s[MAX_N];//����s��
uLL Hash[MAX_N];
map<uLL, int> pre[200005];//pre[len][k]��ʾ����Ϊlen��HashֵΪk�Ĵ���s���г��ּ���
uLL S[MAX_N];//s����Hashֵǰ׺��
P query[MAX_N];//����ѯ��
bool ok[MAX_N];//�жϳ���Ϊlen���Ӵ��Ƿ�����
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        Hash[i] = (LL)rand()*rand()*rand();
    }
    S[0] = 0;
    for(int i=1; i<=n; i++) {
        scanf("%lld", &s[i]);
        S[i] = S[i-1] + Hash[s[i]];
    }
    int m;
    cin >> m;
    for(int mm=0; mm<m; mm++) {
        int k;
        scanf("%d", &k);
        uLL sum = 0;
        for(int i=0; i<k; i++) {
            int x;
            scanf("%d", &x);
            sum += Hash[x];
        }
        query[mm] = P(k, sum);
    }
    memset(ok, false, sizeof(ok));
    for(int i=0; i<m; i++) {
        int len = query[i].first;
        if(ok[len])//����Ϊlen���Ӵ������
            continue;
        for(int j=len; j<=n; j++) {
            uLL tmp = S[j] - S[j-len];
            pre[len][tmp]++;
        }
        ok[len] = true;
    }
    for(int i=0; i<m; i++) {
        int len = query[i].first;
        uLL sum = query[i].second;
        printf("%d\n", pre[len][sum]);
    }
}