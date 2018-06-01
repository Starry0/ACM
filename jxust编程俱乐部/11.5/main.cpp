#include<stdio.h>
#define MAX 100
struct Student
{
char name[20];
int num;
int score[3];
}boy1,boy2;
int main()
{
int n,i,x=0,y=0,z=0;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
scanf("%d%s%d%d%d",&boy1.num,&boy1.name,&boy1.score[0],&boy1.score[1],&boy1.score[2]);
if(boy1.score[0]+boy1.score[1]+boy1.score[2]>boy2.score[0]+boy2.score[1]+boy2.score[2]||i==1)
    boy2=boy1;
x+=boy1.score[0];
y+=boy1.score[1];
z+=boy1.score[2];
}
printf("%d %d %d\n%d %s %d %d %d\n",x/n,y/n,z/n,boy2.num,boy2.name,boy2.score[0],boy2.score[1],boy2.score[2]);
return 0;
}
