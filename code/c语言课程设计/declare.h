/**
*�����ļ�
*@package : SAMS
*@subpackage : declare
*�����궨�塢ȫ�ֱ���������������
* http://youthlin.com/
*/

/*�궨��*/
#define NS 8			//1-6��Ŀ��0ƽ����7��
#define NL 25			//��������
#define CLEAR "cls"		//����
#define P "pause"		//��ͣ


/*�ṹ�嶨��*/
typedef struct student{
	int num;
	char name[NL];          //��������25
	float score[NS];        //NS=8 1-6�ɼ� 0ƽ�� 7�ܷ�
	struct student *next;
}stu;						//�ṹ�壬����
typedef stu * pstu;			//����ָ��

pstu front,rear;			//ȫ������ָ�������ͷ��β
int k=0,people=0;			//k��Ŀ������people����
int ifsave=0;				//����ѱ���  �Ƿ�������  �Ƿ�������
float course[7][2]={{0},{0}};               //ȫ�ֱ���,1-6����6�ſ�Ŀ��0�ܷ�1ƽ����

/*��������*/
//void space();							//�������	@since_v1.4��ȡ��	�˵���̫�಻Ҫ���������
void welcome();							// -1 ��ӭ
void menu();							// 0 �˵�

int read();								// 1  ���ļ�����
int append();							// 2  �ֹ�¼��
int cal_every_cou(pstu head);			// 3  ����ÿ���ſγ̵��ֺܷ�ƽ����
int cal_every_stu(pstu head,int); 		// 4  ����ÿ��ѧ�����ֺܷ�ƽ����
pstu sort_by_total_des(pstu head,int j);		// 5  ��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
pstu sort_by_total_asc(pstu head);		// 6  ��ÿ��ѧ�����ܷ��ɵ͵����ų����α� (��ȡ�� �� i=1�Ӹߵ���	i=0�ӵ͵���
int sort_by_num(pstu head);				// 7  ��ѧ����С�����ų��ɼ���
pstu sort_by_name(pstu head);			// 8  �������ֵ�˳���ų��ɼ���
int search_by_num(pstu head); 			// 9  ��ѧ�Ų�ѯѧ���������俼�Գɼ�
int search_by_name(pstu head);			// 10 ��������ѯѧ���������俼�Գɼ�
int statistic(pstu head);				// 11 ͳ�Ƶȼ��������������ļ�
int list(pstu head,int j);				// 12 ���ÿ��ѧ����ѧ�š����������Ƴɼ��ܷ�ƽ����
int write_to_file(pstu head);			// 13 ��ÿ��ѧ���ĸ�����Ϣ���ɼ�д���ļ�
int quit();								// 0  �˳�

int saveload(pstu head);				// 14 �����浵
int deleteone();							// 15 ɾ��
int help();								// 16 ����

int about();							// 17 ����
int feedback();							//����

//int save(stu stu0);						//����
