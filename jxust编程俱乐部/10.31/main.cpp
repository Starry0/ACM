# include <stdio.h>
void input (int * p);
void paixu (int * p);
void print (int * p);
int main ()
{
int a[10];
input (a);
paixu (a);
print (a);
return 0;
}
void input (int * p)
{
    int *q = p;
    while (p < q + 10)
 {
scanf("%d",p++);
}
}
void paixu (int * p)
{
int *q = p;
int *max = p,*min = p,tmp;
for (;p < q + 10;p++)
{
if (*max < *p)
max = p;
if (*min > *p)
min = p;
}
tmp = *q;
*q = *min;
    *min = tmp;
    if(max == q)//���max��λ�������ǵ�һ��Ԫ�صĵ�ַ�������Ѿ����ı��ˣ�����Ҫ�ĳ��µ�ַ��
    {
        max = min;
    }
 q+=9;
tmp = *q;
*q = *max;
*max = tmp;
}
void print (int * p)
{
    int *q = p;
while (p < q + 10)
{
printf("%d ",*p++);
}
}
