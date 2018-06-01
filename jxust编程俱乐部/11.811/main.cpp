#include <iostream>

using namespace std;
int N,M;
struct student
{
    int num;
    int score;
    student *next;
};
int main()
{
    student *creat(void);
    student *inser(student *,student *);
    student *paixu(student *);
    void print(student *);
    cin>>N>>M;
    student *str,*head,*str1,*str2;
    str1=creat();
    N=M;print(str1);
    str2=creat();print(str2);
    str=inser(str1,str2);
    head=paixu(str);
    print(str);
    return 0;
}
student *creat(void)
{
    student *head,*p1,*p2;
    p2=p1=new student;
    head=p1=NULL;
    while(N--)
    {
        cin>>p1->num>>p1->score;
        p1=new student;
        p1=p1->next;
    }
    p1->next=NULL;
    return(head);
}
student *inser(student *str1,student *str2)
{
    student *p,*head;
    head=str1;
    for(p=str1;p->next!=NULL;p=p->next)
    {

    }
    str1->next=str2;
    return(head);
}
student *pauxu(student *str)
{
    student *p1,*p2,*head;
    int num_temp,score_temp;
    head=str;
    for(p1=head;p1->next!=NULL;p1=p1->next)
        for(p2=p1->next;p2->next!=NULL;p2=p2->next)
    {
        if(p2->num<p1->num)
        {
            num_temp=p2->num;
            p2->num=p1->num;
            p1->num=num_temp;
            score_temp=p2->score;
            p2->score=p1->score;
            p1->score=score_temp;
        }
    }
    return(head);

}
void print(student *str)
{
    student *p1;
    for(p1=str;p1->next!=NULL;p1=p1->next)
        cout<<p1->num<<' '<<p1->score<<endl;
}
