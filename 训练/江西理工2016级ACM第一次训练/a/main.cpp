#include <stdio.h>
int main()
{
	int b[32],i,j,n;
	while(scanf("%d",&n)!=EOF)
	{
		b[0]=1;
		printf("%d\n",b[0]);
		for(i=1;i<n;i++)
		{
			b[i]=1;
			for(j=i-1;j>0;j--)
			{
				b[j]=b[j]+b[j-1];
			}
			for(j=0;j<=i;j++)
			{
				printf("%d",b[j]);
				if(j!=i)
					printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
