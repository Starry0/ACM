#include <cstdio>
#include <cstring>
#include <algorithm>
#define SONG
using namespace std;

const int maxn = 1e6+10;
const int modn = 1e9+7;
#define next HKJournalist
int next[maxn];
int val[maxn];
char sa[maxn], sb[maxn];

void getnext(const char p[], int next[], int val[])
{
    next[0] = -1;
    next[1] = 0;
    val[0] = 0;
    val[1] = 1;
    int l = strlen(p);
    for(int i=1; i<l; i++){
        next[i+1] = 0;
        val[i+1] = i+1;
        for(int j=next[i]; j>=0; j=next[j])
            if(p[i] == p[j]){
                next[i+1] = j+1;
                val[i+1] += val[j+1];
                val[i+1] %= modn;
                break;
            }
    }
#ifdef SONG
    printf("next: ");
    for(int i=0; i<=l; i++)
        printf("%d%c", next[i], " \n"[i==l]);
    printf("value:");
    for(int i=0; i<=l; i++)
        printf("%d%c", val[i], " \n"[i==l]);
#endif
}

int match(const char p[], const int next[], const char t[], const int val[])
{
    int l = strlen(t);
    int ans = 0;
    int j = 0;
    for(int i=0; i<l; i++){
        int k=j;
        for(j=0; k>=0; k=next[k])
            if(t[i] == p[k]){
                j = k+1;
                break;
            }
        ans = (ans + val[j])%modn;
    }
    return ans;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", sa);
        scanf("%s", sb);
        int la = strlen(sa);
        int lb = strlen(sb);
        for(int i=0; i*2<la-1; i++)
            swap(sa[i], sa[la-i-1]);
        for(int i=0; i*2<lb-1; i++)
            swap(sb[i], sb[lb-i-1]);
        getnext(sb, next, val);
        printf("%d\n", match(sb, next, sa, val));
    }
    return 0;
}