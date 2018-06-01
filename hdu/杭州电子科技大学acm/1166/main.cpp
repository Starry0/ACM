#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 55555;
int sum[maxn << 2];//��λ��ƫһλ�൱�ڳ���2��ƫ��2λ�൱�ڳ���2��ƽ��
void PushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];//�����λ�����+1����˼
}

void build(int l, int r, int rt)//�����߶���
{
    if (l == r)
    {
        scanf("%d", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;//��λ��ƫ1λ�൱�ڳ���2
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    PushUp(rt);
}

void update(int p, int add, int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, add, l, m, rt << 1);
    else update(p, add, m + 1, r, rt << 1 | 1);
    PushUp(rt);
}

int query(int ll, int rr, int l, int r, int rt)//��ѯ�߶���
{
    if (ll <= l && rr >= r) return sum[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (ll <= m) ret += query(ll, rr, l, m, rt << 1);
    if (rr > m) ret += query(ll, rr, m + 1, r, rt << 1 | 1);
    return ret;
}

int main()
{
    int t, c;
    char d[10];
    scanf("%d", &t);
    for (c = 1; c <= t; c++)
    {
        printf("Case %d:\n", c);
        int n;
        scanf("%d", &n);
        build(1, n, 1);
        while (scanf("%s", d) != EOF)
        {
            if (d[0] == 'E') break;
            int x, y;
            scanf("%d%d", &x, &y);
            if (d[0] == 'Q')
            {
                int ans = query(x, y, 1, n, 1);
                printf("%d\n", ans);
            }
            if (d[0] == 'S') update(x, -y, 1, n, 1);
            if (d[0] == 'A') update(x, y, 1, n, 1);
        }
    }
    return 0;
}
