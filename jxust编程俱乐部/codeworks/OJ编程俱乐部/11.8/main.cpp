#include <iostream>
#include <string>
using namespace std;
struct student
{
    int xuehao;
    int chji;
    student *next;
};
int main()
{
    int N,M,i,temp,j,num_temp,score_temp;
//	void print(student *head); 
	student *head_a,*head_b,*p1,*p2,*pmin; 
    cin>>N>>M;
    student stu1[N],stu2[M],*head;
  //  head=&stu1[0];
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
    stu1[N-1].next=&stu2[0];
/*    for(i=0;i<(M+N);i++)
    {
        p[i]=head;
        head=head->next;
    }            for(p1=head_a;p1->next!=NULL;p1=p1->next) 
    {
    	pmin=p1;
    	for(p2=p1->next;p2!=NULL;p2=p2->next)
    	if(p2->xuehao<pmin->xuehao) 
    	pmin=p2; 
    	if(pmin!=p1) 
    	{
    		num_temp=p1->xuehao;
    		p1->xuehao=pmin->xuehao;
    		pmin->xuehao=num_temp;
    		
    		score_temp=p1->chji;
    		p1->chji=pmin->chji; 
    		pmin->chji=score_temp;
    		}
    }
    print(head_a);*/
    for(p1=stu1;p1->next!=NULL;p1=p1->next)
    {
    	cout<<p1->xuehao<<" "<<p1->chji;
    }

    return 0;
}

/*void print(student *head){
	student *p1;
	if(head==NULL)
	{
		printf("NULL list!\n");
		return;
	}
	else
	{
		for(p1=head;p1!=NULL;p1=p1->next)
		printf("%d,%.2f\n",p1->xuehao,p1->chji);
	}
}*/