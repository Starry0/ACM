#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int maxn=1001;	//矩形最大边长

int f[maxn][maxn];		//以[0,m]×[0,n]为包含菱形的最小矩形的菱形的个数
long long g[maxn][maxn];//在[0,m]×[0,n]以m,n为边界的菱形的个数
long long h[maxn][maxn];//在[0,m]×[0,n]中菱形的个数
//扩展欧基里德算法，返回结果为最大公约数d，且ax+by=d
int egcd(int a,int b,long long &x,long long &y)
{
	long long k;			//临时变量
	int d;					//最大公约数
	if (b==0)				//终止条件
	{
		x=1;				//满足终止条件时x的值
		y=0; 				//满足终止条件时y的值
		return a;			//最大公约数为a
	}
	else
	{
		d=egcd(b,a%b,x,y);	//递归求解
		k=a/b;
		k=x-k*y;				//临时变量用于交换两个数
		x=y;					//扩展欧基里德算法中，从上一层得到x=y
		y=k;					//扩展欧基里德算法中，从上一层得到y=x-(a/b)*y
		return d;				//最大公约数为递归求解结果
	}
}
//计算区间的上下界
void cal_bound(long long x,long long step,long long &l,long long &r,int lb,int rb)
{
	int temp;
	if (step<0)				//当步长为负数时，进行镜像调整使得步长为正
	{
		x=-x;					//x取相反数
		step=-step;			//步长取相反数
		temp=lb;
		lb=-rb;
		rb=-temp;				//把左右边界取相反数并且交换
	}
	//求最小的l使x+l*step>=lb
	if (lb-x>=0)				//左边界在已知解的右边
		l=(lb-x+step-1)/step;
	else						//左边界在已知解的左边
		l=(lb-x)/step;
	//求最大的r使x+r*step<=rb
	if (rb-x>=0) 				//右边界在已知解的右边
		r=(rb-x)/step;
	else						//右边界在已知解的左边
		r=(rb-x-step+1)/step;
	return;
}
//求ax+by=c在lx<=x<=rx且ly<=y<=ry时整数解的个数
int cal(int a,int b,int c,int lx,int rx,int ly,int ry)
{
	long long x,y,dx,dy,l1,r1,l2,r2;
	int d;
	d=egcd(abs(a),abs(b),x,y);	//使用扩展欧基里德算法
	if (c%d!=0)					//不存在解的情况
		return 0;
	if (a<0)						//如果a为负数，则相应调整x
		x=-x;
	if (b<0) 						//如果b为负数，则相应调整y
		y=-y;
	x*=c/d;						//求出其中一个解的x值
	y*=c/d;						//求出其中一个解的y值
	dx=b/d;						//x的变化步长
	dy=-a/d;						//y的变化步长
	cal_bound(x,dx,l1,r1,lx,rx);//通过x求t的左右边界
	cal_bound(y,dy,l2,r2,ly,ry);//通过y求t的左右边界
	if (l1<l2)					//取左边界的最大值
		l1=l2;
	if (r1>r2)					//取右边界的最小值
		r1=r2;
	return r1-l1+1;				//返回解的个数
}
int init()						//预处理函数
{
	int i,j,temp;
	for(i=1;i<maxn;i++){		//枚举矩形的其中一边长
		for(j=1;j<maxn;j++){	//枚举矩形的另一边长
			temp=cal(2*i,-2*j,i*i-j*j,0,i,0,j);//计算情况(1)的结果
			if (i==j)				//当矩形为正方形时，正方形重复计算了一次
				temp--;
			if (temp>0)
				f[i][j]+=temp;	//将合法解累加到f数组中
			temp=cal(2*i,2*j,i*i+j*j,1,i-1,1,j-1);//计算情况(2)的结果
			if (i%2==0&&j%2==0)	//减去菱形面积为0的情况
				temp--;
			if (temp>0)
				f[i][j]+=temp;	//将合法解累加到f数组中
			//从f数组到g数组的转移方程
			g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1]+f[i][j];
			//从g数组到h数组的转移方程
			h[i][j]=h[i-1][j]+h[i][j-1]-h[i-1][j-1]+g[i][j];
		}
	}
	return 0;
}

int main()
{
	int m,n;
	init();								//预处理
	while(scanf("%d%d",&m,&n)!=EOF){	//输入整数m,n直到文件结束
		printf("%I64d\n",h[m][n]);		//输出答案
	}
	return 0;
}
