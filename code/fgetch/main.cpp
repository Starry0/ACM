#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{
FILE *fp;
char ch;
if((fp=fopen("E:\\code\\code\\iii.txt","rt"))==NULL)
{
printf("\nCannot open file strike any key exit!");
getch();
exit(1);
}
ch=fgetc(fp);
while(ch!=EOF)
{
putchar(ch);
ch=fgetc(fp);
}
fclose(fp);
}
