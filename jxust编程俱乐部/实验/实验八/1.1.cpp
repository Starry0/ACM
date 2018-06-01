#include <stdio.h>
int main()
{
    void fun(int i,int j);
    int i=2,x=5,j=7;
    fun(j,6);           
    printf("i=%d; j=%d; x=%d\n",i,j,x);
    return 0;
}
void fun(int i,int j)
{
    int x=7;
    printf("i=%d; j=%d; x=%d\n",i,j,x);
}
