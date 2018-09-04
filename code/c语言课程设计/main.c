/**
*学生成绩管理系统
*@author Software College of Jilin University Grade 2013 Class 10
*@package Student Achievement Management System(SAMS)
*http://youthlin.com/
*@version 2.0	最终版！
*@licenses 知识共享署名-非商业使用-相同方式共享 4.0 国际许可协议(CC BY-NC-SA 4.0)
*/

/*包含头文件*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include <time.h>
#include "declare.h"			//声明
#include "interface.cpp"		//界面
#include "youthlin.cpp"			//子函数 功能 1、2、5、8、11
#include "zxq.cpp"				//子函数 功能 4 、6、10、13
#include "lrt.cpp"				//子函数 功能 3、7、9、12




/**
*主函数http://youthlin.com/
*@Author Youth.霖
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
		case 1  : read();break;								//从文件读入
		case 2  : append();break;							//手工录入
		case 3  : cal_every_cou(front);break;												//计算每门课程总分平均分
		case 4  : system(CLEAR);cal_every_stu(front,0);break;								//计算每个学生总分平均分
		case 5  : system(CLEAR);front=sort_by_total_des(front,0);list(front,1);break;		//按总分正序
		case 6  : system(CLEAR);front=sort_by_total_asc(front,0);list(front,1);break;		//按总分逆序
		case 7  : sort_by_num(front);list(front,1);break;					//按姓名字典顺序排序
		case 8  : front=sort_by_name(front);list(front,1);break;			//按学号排序
		case 9  : front=sort_by_total_des(front,0);search_by_num(front);break;				//按学号查找
		case 10 : front=sort_by_total_des(front,0);search_by_name(front);break;				//按姓名查找
		case 11 : statistic(front);break;					//统计
		case 12 : system(CLEAR);list(front,0);break;		//列出所有
		case 13 : write_to_file(front);break;				//写入文件
		case 14 : saveload(front);break;					//存档读档
		case 15 : deleteone();break;						//删除
		case 16 : help();break;								//帮助说明
		case 17 : about();break;							//关于
		case 0  : quit();break;								//退出
		case 20131231: a();exit(0); 			//哈哈，有密道。。。纪念我们的2013
		default: printf("Slect Error,input your choice again.t选择错误，请重新选择：tn");//getchar();
		}/*switch*/
			//getchar();http://youthlin.com/
		/*printf("Press any key to continue.tt按任意键继续。tn");
		getchar();
		getchar();
		*/
		/**
		*测试 暂停 sleep函数
		*@link ： http://see.xidian.edu.cn/html/345.html
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
