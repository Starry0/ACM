#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct student{ /*����ṹ��*/
    char name[MAX]; /*����*/
    int num[MAX]; /* ѧ��*/
    char sex[MAX]; /*�Ա�*/
    int chinese; /*����*/
    int mathematic; /* ��ѧ*/
    int english; /*Ӣ��*/
    int computer; /*�����*/
    struct student *next; /*�ṹ��ָ��*/
}stu;
stu *head; /*ͷָ��*/
void print() /*��ʾ���ӡ����*/
{
	system("cls");
	printf("\t\t\t�ɼ�����ϵͳ\n"); /*�ɼ�����ϵͳ*/
	printf("<1>��������\t"); /*��������*/
	printf("<2>��ʾ\t\t"); /*��ʾ*/
	printf("<3>��������\t"); /*��������*/
	printf("<4>��������\t    "); /*��������*/
	printf("<5>��ǰ����\t\t"); /*��ǰ����*/
	printf("<6>��������\n"); /*��������*/
	printf("<7>��������\t"); /*��������*/
	printf("<8>����ƽ���ɼ�\t"); /*����ƽ���ɼ�*/
	printf("<9>��ѧƽ���ɼ�\t"); /*��ѧƽ���ɼ�*/
	printf("<10>Ӣ��ƽ���ɼ�    "); /*Ӣ��ƽ���ɼ�*/
	printf("<11>�����ƽ���ɼ�\t"); /*�����ƽ���ɼ�*/
	printf("<12>�˳�\t\n"); /*�˳�*/
}
void cin(stu *p1) /*����������ݵĺ���*/
{

}
stu *cindata() /*���������Ƿ��������ĺ���*/
{

}
stu *lookdata(stu *p1) /*�鿴���ݵĺ���*/
{

}
void insert() /*ͨ���Ƚ�ѧ�����������ݵĺ���*/
{

}
find(stu *p2) /*ͨ���������Ҳ鿴���ݵĺ���*/
{

}

void maverage() /*���ѧ����ѧƽ���֡���ߺ���ͷֳɼ��ĺ���*/
{

}
void eaverage() /*���ѧ��Ӣ��ƽ���֡���ߺ���ͷֳɼ��ĺ���*/
{

}
void comaverage() /*���ѧ�������ƽ���֡���ߺ���ͷֳɼ��ĺ���*/
{

}
update(stu *p2) /*ͨ��������������������*/
{

}
save(stu *p2) /*�������ݺ���*/
{

}
char password[7]="123456"; /*�����ʼ����*/

int main()
{
    int choice;
    stu *p2;
    char s[8];
    int flag=0,i=1; /*��־��*/
    int n=3;
    do{
        printf("������������:\n");
        scanf("%s",s);
        if(!strcmp(s,password)) /*��������ƥ����֤*/
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
        printf("you have Enter 3 times!"); /*�������볬����3�Σ���*/
        exit(0); /*�Զ��˳�*/
    }
    printf("��ӭ������������ѧ����ѧԺ\n");
    printf(" ��ӭ�����Զ���ϵ\n");
    printf(" �༶:�������\t���:08051051\n"); /*�༶�ͺ���*/
    printf(" �Ƿ����ϵͳ\n"); /*�ʽ���ϵͳ���*/

    scanf("%d",&choice);
    print();
	while (1) {
		printf("Enter choice:");
		getchar();
		scanf("%d",&i);
		if (i<1 || i>13) {
			printf("�ٴ�1-13�н���ѡ��:\n"); /*�ٴ�1-13�н���ѡ��*/
			exit(1);
		}

		switch (i) {
		case 1:p2 = cindata(); /*���������Ƿ��������ĺ���*/
			break;
		case 2:p2 = lookdata(head); /*�鿴���ݵĺ���*/
			break;
		case 3:insert(); /*ͨ���Ƚ�ѧ�����������ݵĺ���*/
			break;
		case 4:find(head); /*ͨ���������Ҳ鿴���ݵĺ���*/
			break;
		case 5:update(head); /*ͨ��������������������*/
			break;
		case 6:save(head); /*�������ݺ���*/
			break;
		case 7:print(); /*��ʾ���ӡ����*/
			break;
		case 8://caverage(); /*���ѧ������ƽ���֡���ߺ���ͷֳɼ��ĺ���*/
			break;
		case 9:maverage(); /*���ѧ����ѧƽ���֡���ߺ���ͷֳɼ��ĺ���*/
			break;
		case 10:eaverage(); /*���ѧ��Ӣ��ƽ���֡���ߺ���ͷֳɼ��ĺ���*/
			break;
		case 11:comaverage(); /*���ѧ�������ƽ���֡���ߺ���ͷֳɼ��ĺ���*/
			break;
		case 12:; /*�ղ���*/
		case 13:exit(1); /*�˳�*/
			break;
		}
		scanf("%d", &i);
	}
    return 0;
}
