#include <stdio.h>
int max(int x,int y,int z)//定义一个max()函数，用来返回输入三个数字中最大的值。
{
    int m;
    if(x>y)m=x;
        else m=y;
    if(m<z)m=z;     //用if判断语句把最大值赋值给m.
    return (m);   //返回m值。
}
int main()
{
    int a,b,c,max_num;//
    printf("请输入三个数字：");
    scanf("%d%d%d",&a,&b,&c);//输入三个数字给a,b,c。
    max_num=max(a,b,c);//调用max函数得出最大值给max_num。
    printf("这三个数字的最大值是：%d",max_num);//输出最大值。
    return 0;
}
