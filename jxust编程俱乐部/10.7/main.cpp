#include<stdio.h>

int n,m;
char str[100],string[100];

void a(char *str)    //��str����str[100]������֮��û�й�ϵ
{                    //������������һ�ۺ����βΣ�ָ�룬��������ݡ�
        int t=0,i;
        i=m-1;
        str=str+i;
        for(;i<n;i++)
        {
                string[t]=*str;
                printf("%c",string[t]);
                str++;
                t++;
        }
}

int main()
{
        printf("input n:\n");
        scanf("%d",&n);


        printf("input str:\n");
        scanf("%s",str);        //������û����gets()����������scanf()�ˡ�

        printf("input m:\n");
        scanf("%d",&m);

        a(str);
        return 0;
}
