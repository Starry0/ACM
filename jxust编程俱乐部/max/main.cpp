#include <stdio.h>
int max(int x,int y,int z)//����һ��max()��������������������������������ֵ��
{
    int m;
    if(x>y)m=x;
        else m=y;
    if(m<z)m=z;     //��if�ж��������ֵ��ֵ��m.
    return (m);   //����mֵ��
}
int main()
{
    int a,b,c,max_num;//
    printf("�������������֣�");
    scanf("%d%d%d",&a,&b,&c);//�����������ָ�a,b,c��
    max_num=max(a,b,c);//����max�����ó����ֵ��max_num��
    printf("���������ֵ����ֵ�ǣ�%d",max_num);//������ֵ��
    return 0;
}
