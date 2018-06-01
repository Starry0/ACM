#include <stdio.h>
#include <string.h>

const int MAXNODE=362880;			//���״̬��

struct State {
	char d[9];						//״̬�е�9���ַ�
	short f;							//���״̬����Ŀ��״̬�����ٲ�����
};
//pow[i]��ʾ(i+1)!
int pow[]={1,2,6,24,120,720,5040,40320};
//4�ֲ�ͬ�Ĳ�������������û�˳��
int rot[4][9]={{1,4,2,0,3,5,6,7,8},{0,2,5,3,1,4,6,7,8},{0,1,2,4,7,5,3,6,8},{0,1,2,3,5,8,6,4,7}};

short ans[MAXNODE];					//����ÿ��״̬�Ľ��
int head,tail;						//�������������ʹ�õĶ���ͷ��β
State Q[MAXNODE];					//�������������ʹ�õĶ���

//�ÿ���չ����һ��״̬�任��һ������
int State2I(State &p)
{
	int ret=0;
	for(int i=0;i<8;i++)			//ʹ�ÿ���չ���Ĺ�ʽ
		for(int j=i+1;j<9;j++) if(p.d[i]>p.d[j]) ret+=pow[7-i];
	return ret;
}

//Ԥ��������״̬����Ŀ��״̬�����ٲ�����
void PreCom()
{
	memset(ans,255,sizeof(ans));	//�������Ϊ-1

	head=-1,tail=0;					//��ʼ������ͷβ
	Q[0].f=0;							//��ʼ״̬������Ϊ0
	for(int i=0;i<9;i++) Q[0].d[i]=i+1;//��ʼ����ʼ״̬
	ans[State2I(Q[0])]=0;			//��ʼ״̬�Ĵ�Ϊ0

	while(head++<tail) {			//����ֱ������Ϊ��
		State &p=Q[head],q;
		q.f=p.f+1;					//����һ�β���
		for(int i=0;i<4;i++) {		//ö��4�ֲ�ͬ�Ĳ���
			//���������û�˳��任
			for(int j=0;j<9;j++) q.d[j]=p.d[rot[i][j]];
			int u=State2I(q);		//�õ���״̬�Ŀ���չ��ֵ
			if(ans[u]<0) {			//���״̬��δ����չ
				ans[u]=q.f;			//����״̬��
				Q[++tail]=q;			//��״̬�ŵ�����ĩ��
			}
		}
	}
}
//������������
void Work()
{
	State p;
	int x;

	while(scanf("%d",&x)==1) {		//��������xֱ���ļ�����
		p.d[0]=x;
		for(int i=1;i<9;i++) {
			scanf("%d",&x);			//������9������
			p.d[i]=x;
		}
		printf("%d\n",ans[State2I(p)]);//ֱ�Ӳ��õ���������
	}
}

int main()
{
	PreCom();							//Ԥ����
	Work();							//�����������
	return 0;
}
