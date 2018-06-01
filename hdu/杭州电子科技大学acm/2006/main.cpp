#include<stdio.h>
main()
{
    int n,s,i,a;
    while(scanf("%d",&n)!=EOF)
    {
        s=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(a%2==1)
            s=s*a;
            else ;
        }
        printf("%d\n",s);
    }
}
