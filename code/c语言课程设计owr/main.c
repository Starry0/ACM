#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct student{ /*定义结构体*/
    char name[MAX]; /*姓名*/
    int num[MAX]; /* 学号*/
    char sex[MAX]; /*性别*/
    int chinese; /*语文*/
    int mathematic; /* 数学*/
    int english; /*英语*/
    int computer; /*计算机*/
    struct student *next; /*结构体指针*/
}stu;
stu *head; /*头指针*/
void print() /*显示或打印函数*/
{
	system("cls");
	printf("\t\t\t成绩管理系统\n"); /*成绩管理系统*/
	printf("<1>输入数据\t"); /*输入数据*/
	printf("<2>显示\t\t"); /*显示*/
	printf("<3>插入数据\t"); /*插入数据*/
	printf("<4>访问数据\t    "); /*访问数据*/
	printf("<5>以前数据\t\t"); /*以前数据*/
	printf("<6>保留数据\n"); /*保留数据*/
	printf("<7>更新数据\t"); /*更新数据*/
	printf("<8>语文平均成绩\t"); /*语文平均成绩*/
	printf("<9>数学平均成绩\t"); /*数学平均成绩*/
	printf("<10>英语平均成绩    "); /*英语平均成绩*/
	printf("<11>计算机平均成绩\t"); /*计算机平均成绩*/
	printf("<12>退出\t\n"); /*退出*/
}
void cin(stu *p1) /*输入相关数据的函数*/
{

}
stu *cindata() /*其他数据是否继续输入的函数*/
{

}
stu *lookdata(stu *p1) /*查看数据的函数*/
{

}
void insert() /*通过比较学号来插入数据的函数*/
{

}
find(stu *p2) /*通过姓名查找查看数据的函数*/
{

}

void maverage() /*求各学生数学平均分、最高和最低分成绩的函数*/
{

}
void eaverage() /*求各学生英语平均分、最高和最低分成绩的函数*/
{

}
void comaverage() /*求各学生计算机平均分、最高和最低分成绩的函数*/
{

}
update(stu *p2) /*通过姓名查找来更新数据*/
{

}
save(stu *p2) /*保留数据函数*/
{

}
char password[7]="123456"; /*定义初始密码*/

int main()
{
    int choice;
    stu *p2;
    char s[8];
    int flag=0,i=1; /*标志项*/
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
            printf("Error Enter again:\n");
            n--;
            }
        }while(n>0);
    if(!flag){
        printf("you have Enter 3 times!"); /*输入密码超过了3次！！*/
        exit(0); /*自动退出*/
    }
    printf("欢迎来到东华理工大学长江学院\n");
    printf(" 欢迎来到自动化系\n");
    printf(" 班级:软件技术\t班号:08051051\n"); /*班级和号码*/
    printf(" 是否进入系统\n"); /*问进入系统与否*/

    scanf("%d",&choice);
    print();
	while (1) {
		printf("Enter choice:");
		getchar();
		scanf("%d",&i);
		if (i<1 || i>13) {
			printf("再从1-13中进行选择:\n"); /*再从1-13中进行选择*/
			exit(1);
		}

		switch (i) {
		case 1:p2 = cindata(); /*其他数据是否继续输入的函数*/
			break;
		case 2:p2 = lookdata(head); /*查看数据的函数*/
			break;
		case 3:insert(); /*通过比较学号来插入数据的函数*/
			break;
		case 4:find(head); /*通过姓名查找查看数据的函数*/
			break;
		case 5:update(head); /*通过姓名查找来更新数据*/
			break;
		case 6:save(head); /*保留数据函数*/
			break;
		case 7:print(); /*显示或打印函数*/
			break;
		case 8://caverage(); /*求各学生语文平均分、最高和最低分成绩的函数*/
			break;
		case 9:maverage(); /*求各学生数学平均分、最高和最低分成绩的函数*/
			break;
		case 10:eaverage(); /*求各学生英语平均分、最高和最低分成绩的函数*/
			break;
		case 11:comaverage(); /*求各学生计算机平均分、最高和最低分成绩的函数*/
			break;
		case 12:; /*空操作*/
		case 13:exit(1); /*退出*/
			break;
		}
		scanf("%d", &i);
	}
    return 0;
}
