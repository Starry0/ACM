#include"stdio.h"
#include"stddef.h"
#include "stdlib.h"
#include"string.h"
#define MAX 10
typedef struct student{ /*定义结构体*/
    char name[MAX]; /*姓名*/
    int num; /* 学号*/
    int age; /*年龄*/
    char sex[MAX]; /*性别*/
    int mathematic; /* 数学*/
    int english; /*英语*/
    int computer; /*C语言*/
    struct student *next; /*结构体指针*/
}stu;
stu *head; /*头指针*/
void print() /*显示或打印函数*/
{
    system("cls");
    printf("\t\t\t成绩管理系统\n"); /*成绩管理系统*/
    printf("<1>输入数据\t"); /*输入数据*/
    printf("<2>显示\t\t"); /*显示*/
    printf("<3>插入数据\t    "); /*插入数据*/
    printf("<4>访问数据\t\t"); /*访问数据*/
    printf("<5>删除数据\t"); /*以前数据*/
    printf("<6>保留数据\n"); /*保留数据*/
    printf("<7>刷新\t\t"); /*更新数据*/
    printf("<8>高数平均成绩\t"); /*数学平均成绩*/
    printf("<9>英语平均成绩    "); /*英语平均成绩*/
    printf("<10>C语言平均成绩\t"); /*计算机平均成绩*/
    printf("<11>退出\t\n"); /*退出*/
}

void cin(stu *p1) /*输入相关数据的函数*/
{
    printf("姓名:\n");
    scanf("%s",&p1->name);
    printf("学号:\n");
    scanf("%d",&p1->num);
    printf("年龄:\n");
    scanf("%d",&p1->age);
    printf("性别:\n");
    scanf("%s",&p1->sex);
    printf("高数:\n");
    scanf("%d",&p1->mathematic);
    printf("英语:\n");
    scanf("%d",&p1->english);
    printf("C语言:\n");
    scanf("%d",&p1->computer);
}
stu *cindata() /*其他数据是否继续输入的函数*/
{
    stu *p1,*p2;
    int i=1;
    char ch;
    p1=(stu *)malloc(sizeof(stu));
    head=p1;
    while(i)
        {
            cin(p1);
            printf("是否继续输入数据?y/n"); /*是否继续输入数据*/
            ch=getchar();
            ch=getchar();
            if(ch=='n'||ch=='N'){
                i=0;
                p1->next=NULL;
                }
            else{
                p2=p1;
                p1=(stu *)malloc(sizeof(stu));
                p2->next=p1;
            }
        }
    return(p1->next);
}

stu *lookdata(stu *p1) /*查看数据的函数*/
{
    while(p1!=NULL){
        printf("姓名:%5s\t",p1->name);
        printf("学号:%6d\t",p1->num);
        printf("年龄:%5d\t",p1->age);
        printf("性别:%5s\t",p1->sex);
        printf("\n");
        printf("高数:%5d\t",p1->mathematic);
        printf("英语:%5d\t",p1->english);
        printf("C语言:%5d\t",p1->computer);
        printf("\n");
        p1=p1->next;
    }
    return p1;
}

void insert() /*通过比较学号来插入数据的函数*/
{
    stu *p1,*p3,*p2;
    char ch;
    p1=head;
    p3=(stu *)malloc(sizeof(stu));

    p3->next=NULL;
    if(head==NULL){ head=p3; return;}
    cin(p3);
    while(p1!=NULL&&(p1->num<p3->num)) /*通过学号的比较来插入*/
    {
        p2=p1;p1=p1->next;
    }
    if(p2==head) {
        p3->next=head;
        head=p3;
        return;
    }
    p3->next=p1;
    p2->next=p3;
}

void find(stu *p2) /*通过姓名查找查看数据的函数*/
{
    char name[20];
    int b=0;
    printf("输入你想要查找学生的名字:"); /*通过姓名查看*/
    scanf("%s",name);
    while(p2!=NULL){
        if(strcmp(name,p2->name)==0)
        {
            printf("你想要的数据找到了\n");
            printf("名字:%5s\t",p2->name);
            printf("学号:%6d\t",p2->num);
            printf("年龄:%5d\t",p2->age);
            printf("性别%5s\t",p2->sex);
            printf("\n");
            printf("高数:%5d\t",p2->mathematic);
            printf("英语:%5d\t",p2->english);
            printf("C语言:%5d\t",p2->computer);
            printf("\n");

            b=1;
            }
        p2=p2->next;
        }

        if(b==0)
            printf("抱歉，没有找到！\n");
       // print();
}


void maverage() /*求各学生数学平均分、最高和最低分成绩的函数*/
{
    stu *p1;
    int i;
    float max=0.0,min=200.0;
    float sum=0.0,aver=0;
    p1=head;
    if(p1==NULL)
    printf("没有数据！");
    else{
        for(i=0;p1!=NULL;i++,p1=p1->next)
        sum+=p1->mathematic;
    aver=sum/i;

    p1=head;
    for(i=0;p1!=NULL;i++,p1=p1->next){
        if(max<p1->mathematic)
        max=p1->mathematic;
    }
    p1=head;
    for(i=0;p1!=NULL;i++,p1=p1->next)
        if(min>p1->mathematic)
        min=p1->mathematic;
        }
    printf("高数平均分:%.2f\t",aver);
    printf("高数最高分:%.2f\t",max);
    printf("高数最低分:%.2f\n",min);
}

void eaverage() /*求各学生英语平均分、最高和最低分成绩的函数*/
{
    stu *p1;
    int i;
    float max=0.0,min=200.0;
    float sum=0.0,aver=0;
    p1=head;
    if(p1==NULL)
    printf("没有数据！");
    else{
        for(i=0;p1!=NULL;i++,p1=p1->next)
            sum+=p1->english;
        aver=sum/i;

        p1=head;
        for(i=0;p1!=NULL;i++,p1=p1->next){
            if(max<p1->english)
            max=p1->english;
        }
        p1=head;
        for(i=0;p1!=NULL;i++,p1=p1->next)
            if(min>p1->english)
            min=p1->english;
        }
    printf("英语平均分:%.2f\t",aver);
    printf("英语最高分:%.2f\t",max);
    printf("语言最低分:%.2f\n",min);
}

void comaverage() /*求各学生C语言平均分、最高和最低分成绩的函数*/
{
    stu *p1;
    int i;
    float max=0.0,min=200.0;
    float sum=0.0,aver=0;
    p1=head;
    if(p1==NULL)
    printf("没有数据！");
    else{
        for(i=0;p1!=NULL;i++,p1=p1->next)
            sum+=p1->computer;
        aver=sum/i;

        p1=head;
        for(i=0;p1!=NULL;i++,p1=p1->next){
            if(max<p1->computer)
            max=p1->computer;
        }
        p1=head;
        for(i=0;p1!=NULL;i++,p1=p1->next)
                if(min>p1->computer)
                min=p1->computer;
        }
        printf("C语言平均分:%.2f\t",aver);
        printf("C语言最高分:%.2f\t",max);
        printf("C语言最低分:%.2f\n",min);
}

void Delete(stu *p2) /*通过姓名来删除数据*/
{
    stu *p3;
    p3=(stu *)malloc(sizeof(stu));
    p3=p2;
    char name[10]; /*p2为指向结构体struct student的指针*/
    int b=0;
    printf("输入名字:"); /*输入姓名*/
    scanf("%s",name);
    if(strcmp(name,p2->name)==0){
        head=p2->next;
        printf("已经删除%s的记录\n",name);
    }
    while(p2!=NULL){
        if(strcmp(name,p2->name)==0){
            //printf("找到了\n");
            /*scanf("名字:%s",p2->name);
            scanf("学号:%s",p2->num);
            scanf("年龄:%d",p2->age);
            scanf("性别:%s",p2->sex);
            scanf("高数:%d",p2->mathematic);
            scanf("英语:%d",p2->english);
            scanf("C语言:%d",p2->computer);
            printf("Success!");*/
            p3->next=p2->next;
            b=1;
            goto tt;
            }
        p3=p2;
        tt : p2=p2->next;}
        if(b==0)
            printf("抱歉，没有找到！\n");
        else
            printf("已经删除了%s的记录\n",name);
        //print();
}

void save(stu *p2) /*保留数据函数*/
{
    FILE *fp;
    char file[10];
    printf("输入文件名："); /*输入文件名*/
    scanf("%s",file);
    fp=fopen(file,"w+");
    fprintf(fp,"%s\t","姓名");
    fprintf(fp,"%s\t","学号");
    fprintf(fp,"%s\t","年龄");
    fprintf(fp,"%s\t","性别");
    fprintf(fp,"%s\t","高数");
    fprintf(fp,"%s\t","英语");
    fprintf(fp,"%s\n","C语言");
    while(p2!=NULL){
        fprintf(fp,"%s\t",p2->name);
        fprintf(fp,"%d\t",p2->num);
        fprintf(fp,"%d\t",p2->age);
        fprintf(fp,"%s\t",p2->sex);
        fprintf(fp,"%d\t",p2->mathematic);
        fprintf(fp,"%d\t",p2->english);
        fprintf(fp,"%d\n",p2->computer);
        p2=p2->next;
    }
    fclose(fp);
}

char password[7]="123456"; /*定义初始密码*/

void main(int argc,char *argv[]) /*主函数*/
{
    int choice;
    stu *p2;
    char s[8];
    int flag=0,i; /*标志项*/
    int n=3;
    do{
        printf("你请输入密码:\n");
        scanf("%s",s);
        if(!strcmp(s,password)) /*进行密码匹配验证*/
        {
            printf("PASS\n\n\n");
            flag=1;
            break;
        }
        else{
            printf("密码错误，请在输入一遍:\n");
            n--;
            }
        }while(n>0);
    if(!flag){
        printf("您输入密码超过三次了！"); /*输入密码超过了3次！！*/
        exit(0); /*自动退出*/
    }
/*密码验证成功后进入的界面*/

    printf("欢迎来到东华理工大学长江学院\n");
    printf(" 欢迎来到自动化系\n");
    printf(" 班级:自动化  班\t学号:123456789\n"); /*班级和号码*/
    printf(" 是否进入系统\n"); /*问进入系统与否*/

    scanf("%d",&choice);
    if(choice=='n'||choice=='N')
            exit(1);

    print();
    while(1){
        printf("请选择:");
        getchar();
        scanf("%d",&i);
        if(i<1||i>13){
            printf("再从1-13中进行选择:\n"); /*再从1-13中进行选择*/
            exit(1);
        }

        switch(i){
            case 1:p2=cindata(); /*其他数据是否继续输入的函数*/
                    break;
            case 2:p2=lookdata(head); /*查看数据的函数*/
                    break;
            case 3:insert(); /*通过比较学号来插入数据的函数*/
                    break;
            case 4:find(head); /*通过姓名查找查看数据的函数*/
                    break;
            case 5:Delete(head); /*通过姓名来输出数据的函数*/
                    break;
            case 6:save(head); /*保留数据函数*/
                    break;
            case 7:print(); /*显示或打印函数*/
                    break;
            case 8:maverage(); /*求各学生数学平均分、最高和最低分成绩的函数*/
                    break;
            case 9:eaverage(); /*求各学生英语平均分、最高和最低分成绩的函数*/
                    break;
            case 10:comaverage(); /*求各学生计算机平均分、最高和最低分成绩的函数*/
                    break;
            case 11:; /*空操作*/
            case 12:exit(1); /*退出*/
                    break;
            }
       // scanf("%d",&i);
        }
}

//密码123456
