/**
*ѧ���ɼ�����ϵͳ
*@author Software College of Jilin University Grade 2013 Class 10
*@package Student Achievement Management System(SAMS)
*http://youthlin.com/
*@version 2.0	���հ棡
*@licenses ֪ʶ��������-����ҵʹ��-��ͬ��ʽ���� 4.0 �������Э��(CC BY-NC-SA 4.0)
*/

/*����ͷ�ļ�*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include <time.h>
#include "declare.h"			//����
#include "interface.cpp"		//����
#include "youthlin.cpp"			//�Ӻ��� ���� 1��2��5��8��11
#include "zxq.cpp"				//�Ӻ��� ���� 4 ��6��10��13
#include "lrt.cpp"				//�Ӻ��� ���� 3��7��9��12




/**
*������http://youthlin.com/
*@Author Youth.��
@since version 0.0.1
*@LastUpDate 2013-12
*/
int main(int argc,char *argv[]){
	int choice;
	if(argc!=1){
		help();
		getchar();
	}
	welcome();
	menu();
	scanf("%d",&choice);
	a();
	getchar();
	while(1){
		switch (choice){
		case 1  : read();break;								//���ļ�����
		case 2  : append();break;							//�ֹ�¼��
		case 3  : cal_every_cou(front);break;												//����ÿ�ſγ��ܷ�ƽ����
		case 4  : system(CLEAR);cal_every_stu(front,0);break;								//����ÿ��ѧ���ܷ�ƽ����
		case 5  : system(CLEAR);front=sort_by_total_des(front,0);list(front,1);break;		//���ܷ�����
		case 6  : system(CLEAR);front=sort_by_total_asc(front,0);list(front,1);break;		//���ܷ�����
		case 7  : sort_by_num(front);list(front,1);break;					//�������ֵ�˳������
		case 8  : front=sort_by_name(front);list(front,1);break;			//��ѧ������
		case 9  : front=sort_by_total_des(front,0);search_by_num(front);break;				//��ѧ�Ų���
		case 10 : front=sort_by_total_des(front,0);search_by_name(front);break;				//����������
		case 11 : statistic(front);break;					//ͳ��
		case 12 : system(CLEAR);list(front,0);break;		//�г�����
		case 13 : write_to_file(front);break;				//д���ļ�
		case 14 : saveload(front);break;					//�浵����
		case 15 : deleteone();break;						//ɾ��
		case 16 : help();break;								//����˵��
		case 17 : about();break;							//����
		case 0  : quit();break;								//�˳�
		case 20131231: a();exit(0); 			//���������ܵ��������������ǵ�2013
		default: printf("Slect Error,input your choice again.tѡ�����������ѡ��tn");//getchar();
		}/*switch*/
			//getchar();http://youthlin.com/
		/*printf("Press any key to continue.tt�������������tn");
		getchar();
		getchar();
		*/
		/**
		*���� ��ͣ sleep����
		*@link �� http://see.xidian.edu.cn/html/345.html
		*@Date : 2013-12-26 08:42
		*//*
		for (int i=0;i<2;i++){
			system(CLEAR);
			printf("i=%d",i);
			Sleep(1000);
		}
		*/
		a();
		system(P);
		menu();
		//getchar();
		scanf("%d",&choice);
		//printf("%d",choice);
	}/*while(1)*/
	return 0;
}/*main*/
