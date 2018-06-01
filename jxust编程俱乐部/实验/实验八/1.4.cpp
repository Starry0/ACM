#include <stdio.h>
int main()
{
    void change(int a[]);
    int i,a[5]={1,2,3,4,5};
    for(i=0;i<5;i++)
        printf("%d%c",a[i],i==4?'\n':' ');
    change(a);      
    for(i=0;i<5;i++)
        printf("%d%c",a[i],i==4?'\n':' ');
    return 0;
}
void change(int b[])
{
    int i;
    for(i=0;i<5;i++)
        b[i]=b[i]+5;
}
