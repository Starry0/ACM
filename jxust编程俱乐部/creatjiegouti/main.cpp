#include <iostream>
using namespace std;
struct student
{
    long num;
    float score;
    student *next;
};
int n;
student *creat(void)
{
    student *head;
    student *p1,*p2;
    n=0;
    p1=p2=new student;
    cin>>p1->num>>p1->score;
    head=NULL;
    while(p1->next!=NULL)
    {
        n+=1;
        if(n==1)head=p1;
        else p2->next=p1;
        p2=p1;
        p1=new student;
        cin>>p1->num>>p1->score;
    }
    p2->next=NULL;
    return (head);
}
student *insert(student *head,student *stud)
{
    student *p0,*p1,*p2;
    p1=head;
    p0=stud;
    if(head==NULL)
    {
        head=p0;p0->next=NULL;
    }
    else {
        while((p0->num>p1->num)&&(p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
            if(p0->num<=p1->num)
            {
                if(head==p1)head=p0;
                else p2->next=p0;
                p0->next=p1;
            }
            else {
                p1->next=p0;p0->next=NULL;
            }
            n+=1;
            return (head);
        }
    }
}
student *del(student *head,long num)
{
    student *p1,*p2;
    if(head==NULL)
    {
        cout<<"list null!"<<endl;return(head);
    }
    p1=head;
    while(num!=p1->num&&p1->next!=NULL)
    {
        p2=p1;p1=p1->next;
    }
    if(num==p1->num)
    {
        if(p1==head)head=p1->next;
        else p2->next=p1->next;
        cout<<"delete:"<<num<<endl;
        n-=1;
    }
    else cout<<"cannot find"<<num;
    return(head);
}
void print(student *head)
{
    student *p1;
    for(p1=head;p1->next!=NULL;p1=p1->next)
        cout<<p1->num<<" "<<p1->score;
}
int main()
{
    student *del(student *,long );
    void print(student *);
    student *insert(student *,student * );
    student *creat(void);
    student *head,stu;
    long del_num;
    cout<<"input records:"<<endl;
    head=creat();
    print(head);
    cout<<endl<<"input the deleted number:";
    cin>>del_num;
    head=del(head,del_num);
    print(head);
    cout<<endl<<"input the inserted record:";
    stu=new student;
    cin>>stu.num>>stu.score;
    head=insert(head,&stu);
    print(head);
    return 0;
}
