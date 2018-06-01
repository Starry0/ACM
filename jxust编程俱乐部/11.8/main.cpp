#include <iostream>
#include <string>
using namespace std;
int N,M;
struct student
{
    int xuehao;
    int chji;
    student *next;
};
int main()
{
    student *insert(struct student *,struct student *);
    int i,temp;
    cin>>N>>M;
    student stu1[N],stu2[M],*head,*p[M+N],*p1,*pmin,*p2;
    head=&stu1[0];
    for(i=0;i<N;i++)
        {
            cin>>stu1[i].xuehao>>stu1[i].chji;
            if(i=N-1)
                stu1[i].next=NULL;
            else stu1[i].next=&stu1[i+1];
        }
    for(i=0;i<M;i++)
        {
            cin>>stu2[i].xuehao>>stu2[i].chji;
            if(i=M-1)
                stu2[i].next=NULL;
            else stu2[i].next=&stu2[i+1];
        }
   /* stu1[N-1].next=&stu2[0];
    for(i=0;i<(M+N);i++)
    {
        p[i]=head;
        head=head->next;
    }
  for(p1=head;p1->next!=NULL;p1=p1->next)
    {
    	pmin=p1;
    	for(p2=p1->next;p2!=NULL;p2=p2->next)
    	if(p2->xuehao<pmin->xuehao)
    	pmin=p2;
    	if(pmin!=p1)
    	{
    		temp=p1->xuehao;
    		p1->xuehao=pmin->xuehao;
    		pmin->xuehao=temp;

    		temp=p1->chji;
    		p1->chji=pmin->chji;
    		pmin->chji=temp;
    		}
    }*/
    head=insert(stu1,stu2);
    for(p1=head;p1->next!=NULL;p1=p1->next)
    {
        cout<<p1->xuehao<<" "<<p1->chji<<endl;
    }
    return 0;
}
student *insert(struct student *ah,struct student *bh)
{
    struct student *pa1,*pa2,*pb1,*pb2;
    pa2=pa1=ah;
    pb2=pb1=bh;
    do
    {
        while((pb1->xuehao>pa1->xuehao)&&(pa1->next!=NULL))
        {
            pa2=pa1;
            pa1=pa1->next;
        }
        if(pb1->xuehao<=pa1->xuehao)
        {
            if(ah==pa1)
                ah=pb1;
            else
                pa2->next=pb1;
            pb1=pb1->next;
            pb2->next=pa1;
            pa2=pb2;
            pb2=pb1;
        }
    //}while((pa1->next!=NULL)||(pa1==NULL&&pb1!=NULL));
    }while(pa1->next!=NULL && pb1!=NULL);
    if(pb1!=NULL)
        pa1->next=pb1;
    //if((pb1->num>pa1->num)&&(pa1->next==NULL))
    //    pa1->next=pb1;
    return(ah);
}



/*#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct student{

int num;
float score;
struct student *next;
} STU;

int main(){
	setbuf(stdout,NULL);
	STU *creat();
	void print(STU *head);
	STU *head_a,*head_b,*p1,*p2,*pmin;
	int num_temp;
	float score_temp;
	printf("Input the records of a:\n");
	head_a=creat();
	printf("a:\n");
    print(head_a);
    printf("Input the records of b:\n");
    head_b=creat();
    printf("b:\n");
    print(head_b);
    for(p1=head_a;p1!=NULL;p1=p1->next)
    p2=p1;
    p2->next=head_b;

    printf("After connected:\n");
    print(head_a);

    for(p1=head_a;p1->next!=NULL;p1=p1->next)
    {
    	pmin=p1;
    	for(p2=p1->next;p2!=NULL;p2=p2->next)
    	if(p2->num<pmin->num)
    	pmin=p2;
    	if(pmin!=p1)
    	{
    		num_temp=p1->num;
    		p1->num=pmin->num;
    		pmin->num=num_temp;

    		score_temp=p1->score;
    		p1->score=pmin->score;
    		pmin->score=score_temp;
    		}
    }
    printf("After sorted:\n");
    print(head_a);
    return 0;
}
STU *creat(){
	STU *p1,*p2,*head=NULL;
	int n=0;
	p1=(STU *)malloc(sizeof(STU));
	p2=p1;
	scanf("%d%f",&p1->num,&p1->score);
	while(p1->num!=0)
	{
		n++;
		if(n==1)
		head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(STU *)malloc(sizeof(STU));
		scanf("%d%f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return head;
}

void print(STU *head){
	STU *p1;
	if(head==NULL)
	{
		printf("NULL list!\n");
		return;
	}
	else
	{
		for(p1=head;p1!=NULL;p1=p1->next)
		printf("%d,%.2f\n",p1->num,p1->score);
	}
}*/
