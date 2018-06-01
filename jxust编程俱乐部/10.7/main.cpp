#include<stdio.h>

int n,m;
char str[100],string[100];

void a(char *str)    //此str并非str[100]，两者之间没有关系
{                    //建议你重新捋一捋函数形参，指针，数组的内容。
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
        scanf("%s",str);        //这里我没有用gets()函数，换成scanf()了。

        printf("input m:\n");
        scanf("%d",&m);

        a(str);
        return 0;
}
