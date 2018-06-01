#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 10005

struct bigint
{
    char num[MAX];
    int flag;  // 1:positive -1:negative
    int dgts;
    bigint(void)
    {
        memset(num, '0', sizeof(num));
    }
};

void BigIntTrans(char str[], bigint* a)   //convert string to the structure of bigint
{
    int i, k, len;
    len = strlen(str);
    a->flag = 1;
    a->dgts = len;
    k = 0;
    for(i = len - 1; i >= 1; --i)
        a->num[k++] = str[i];
    if(str[0] == '-') {
        a->flag = -1;
        --a->dgts;
    }
    else {
        a->num[k++] = str[i];
    }
}

void BigIntPrint(bigint* a)
{
    int i;
    if(a->flag == -1) printf("-");
    if(a->dgts == 1 && a->num[0] == '0') {
        printf("0\n");
        return;
    }
    i = a->dgts - 1;
    while(a->num[i] == '0')
        --i;
    for( ; i >= 0; --i) {
        printf("%c", a->num[i]);
    }
    printf("\n");
}

void add(bigint* a, bigint* b, bigint* ans)
{
    int i, c=0, len, tmp;
    len = (a->dgts >= b->dgts? a->dgts:b->dgts);
    for(i = 0; i < len; ++i) {
        tmp = (a->num[i]-'0') + (b->num[i]-'0') + c;
        if(tmp >= 10){
            c = 1;
            ans->num[i] = (tmp % 10) + '0';
        }
        else {
            c = 0;
            ans->num[i] = tmp + '0';
        }
    }
    if(c) {
        ans->num[i] = '1';
        ans->dgts = len + 1;
    }
    else ans->dgts = len;
    if(a->flag + b->flag == 2) ans->flag = 1;
    else ans->flag = -1;
}

void sub(bigint* a, bigint* b, bigint* ans)
{
    int i, c=0, tmp;
    for(i = 0; i < a->dgts; ++i) {
        tmp = (a->num[i]-'0') - (b->num[i]-'0') - c;
        if(tmp >= 0) {
            ans->num[i] = tmp + '0';
            c = 0;
        }
        else {
            ans->num[i] = tmp + 10 + '0';
            c = 1;
        }
    }
    ans->dgts = a->dgts;
    ans->flag = a->flag;
}

int cmpabs(bigint* a, bigint* b)
{
    if(a->dgts > b->dgts)
        return 1;
    else if(a->dgts < b->dgts)
        return 2;
    else {
        for(int i = a->dgts - 1; i >= 0; --i) {
            if(a->num[i] > b->num[i]) return 1;
            else if(a->num[i] < b->num[i]) return 2;
            else continue;
        }
        return 0;
    }
}

void BigIntAdd(bigint* a, bigint* b, bigint* ans)
{
    int flag;
    if(a->flag * b->flag == 1)
        add(a, b, ans);
    else if(a->flag * b->flag == -1) {
        flag = cmpabs(a, b);
        if(flag == 1) sub(a, b, ans);
        else if(flag == 2) sub(b, a, ans);
        else {
            ans->dgts = 1;
            ans->num[0] = '0';
            ans->flag = 1;
        }
    }

}

char str1[MAX], str2[MAX];

int main()
{
    bigint a, b, ans;
    scanf("%s%s", str1, str2);
    BigIntTrans(str1, &a);
    BigIntTrans(str2, &b);
    sub(&a, &b, &ans);
    BigIntPrint(&ans);
    BigIntAdd(&a, &b, &ans);
    BigIntPrint(&ans);
    return 0;
}
