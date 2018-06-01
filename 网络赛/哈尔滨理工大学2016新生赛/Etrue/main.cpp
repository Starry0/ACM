#include <stdio.h>
#include <string.h>

const int MAXNODE=362880;			//最大状态数

struct State {
	char d[9];						//状态中的9个字符
	short f;							//这个状态到达目标状态的最少操作数
};
//pow[i]表示(i+1)!
int pow[]={1,2,6,24,120,720,5040,40320};
//4种不同的操作的逆操作的置换顺序
int rot[4][9]={{1,4,2,0,3,5,6,7,8},{0,2,5,3,1,4,6,7,8},{0,1,2,4,7,5,3,6,8},{0,1,2,3,5,8,6,4,7}};

short ans[MAXNODE];					//到达每个状态的结果
int head,tail;						//广度优先搜索中使用的队列头与尾
State Q[MAXNODE];					//广度优先搜索中使用的队列

//用康托展开把一个状态变换成一个整数
int State2I(State &p)
{
	int ret=0;
	for(int i=0;i<8;i++)			//使用康托展开的公式
		for(int j=i+1;j<9;j++) if(p.d[i]>p.d[j]) ret+=pow[7-i];
	return ret;
}

//预处理所有状态到达目标状态的最少操作数
void PreCom()
{
	memset(ans,255,sizeof(ans));	//清空数组为-1

	head=-1,tail=0;					//初始化队列头尾
	Q[0].f=0;							//初始状态操作数为0
	for(int i=0;i<9;i++) Q[0].d[i]=i+1;//初始化初始状态
	ans[State2I(Q[0])]=0;			//初始状态的答案为0

	while(head++<tail) {			//运算直到队列为空
		State &p=Q[head],q;
		q.f=p.f+1;					//经过一次操作
		for(int i=0;i<4;i++) {		//枚举4种不同的操作
			//按操作的置换顺序变换
			for(int j=0;j<9;j++) q.d[j]=p.d[rot[i][j]];
			int u=State2I(q);		//得到新状态的康托展开值
			if(ans[u]<0) {			//这个状态并未被扩展
				ans[u]=q.f;			//更新状态答案
				Q[++tail]=q;			//新状态放到队列末端
			}
		}
	}
}
//处理输入和输出
void Work()
{
	State p;
	int x;

	while(scanf("%d",&x)==1) {		//输入整数x直到文件结束
		p.d[0]=x;
		for(int i=1;i<9;i++) {
			scanf("%d",&x);			//共输入9个数字
			p.d[i]=x;
		}
		printf("%d\n",ans[State2I(p)]);//直接查表得到结果并输出
	}
}

int main()
{
	PreCom();							//预处理
	Work();							//处理输入输出
	return 0;
}
