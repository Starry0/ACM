/**
*声明文件
*@package : SAMS
*@subpackage : declare
*包括宏定义、全局变量、函数声明等
* http://youthlin.com/
*/

/*宏定义*/
#define NS 8			//1-6科目，0平均，7总
#define NL 25			//姓名长度
#define CLEAR "cls"		//清屏
#define P "pause"		//暂停


/*结构体定义*/
typedef struct student{
	int num;
	char name[NL];          //姓名长度25
	float score[NS];        //NS=8 1-6成绩 0平均 7总分
	struct student *next;
}stu;						//结构体，链表
typedef stu * pstu;			//链表指针

pstu front,rear;			//全局链表指针变量，头、尾
int k=0,people=0;			//k科目门数、people人数
int ifsave=0;				//如果已保存  是否已正序  是否已逆序
float course[7][2]={{0},{0}};               //全局变量,1-6保存6门科目的0总分1平均分

/*函数声明*/
//void space();							//输出空行	@since_v1.4已取消	菜单项太多不要间隔空行了
void welcome();							// -1 欢迎
void menu();							// 0 菜单

int read();								// 1  从文件读入
int append();							// 2  手工录入
int cal_every_cou(pstu head);			// 3  计算每个门课程的总分和平均分
int cal_every_stu(pstu head,int); 		// 4  计算每个学生的总分和平均分
pstu sort_by_total_des(pstu head,int j);		// 5  按每个学生的总分由高到低排出名次表
pstu sort_by_total_asc(pstu head);		// 6  按每个学生的总分由低到高排出名次表 (已取消 ： i=1从高到低	i=0从低到高
int sort_by_num(pstu head);				// 7  按学号由小到大排出成绩表
pstu sort_by_name(pstu head);			// 8  按姓名字典顺序排出成绩表
int search_by_num(pstu head); 			// 9  按学号查询学生排名及其考试成绩
int search_by_name(pstu head);			// 10 按姓名查询学生排名及其考试成绩
int statistic(pstu head);				// 11 统计等级并将结果输出至文件
int list(pstu head,int j);				// 12 输出每个学生的学号、姓名、各科成绩总分平均分
int write_to_file(pstu head);			// 13 将每个学生的个人信息及成绩写入文件
int quit();								// 0  退出

int saveload(pstu head);				// 14 读档存档
int deleteone();							// 15 删除
int help();								// 16 帮助

int about();							// 17 关于
int feedback();							//反馈

//int save(stu stu0);						//保存
