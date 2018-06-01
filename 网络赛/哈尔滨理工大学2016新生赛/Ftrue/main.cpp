#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int maxn=1001;	//�������߳�

int f[maxn][maxn];		//��[0,m]��[0,n]Ϊ�������ε���С���ε����εĸ���
long long g[maxn][maxn];//��[0,m]��[0,n]��m,nΪ�߽�����εĸ���
long long h[maxn][maxn];//��[0,m]��[0,n]�����εĸ���
//��չŷ������㷨�����ؽ��Ϊ���Լ��d����ax+by=d
int egcd(int a,int b,long long &x,long long &y)
{
	long long k;			//��ʱ����
	int d;					//���Լ��
	if (b==0)				//��ֹ����
	{
		x=1;				//������ֹ����ʱx��ֵ
		y=0; 				//������ֹ����ʱy��ֵ
		return a;			//���Լ��Ϊa
	}
	else
	{
		d=egcd(b,a%b,x,y);	//�ݹ����
		k=a/b;
		k=x-k*y;				//��ʱ�������ڽ���������
		x=y;					//��չŷ������㷨�У�����һ��õ�x=y
		y=k;					//��չŷ������㷨�У�����һ��õ�y=x-(a/b)*y
		return d;				//���Լ��Ϊ�ݹ������
	}
}
//������������½�
void cal_bound(long long x,long long step,long long &l,long long &r,int lb,int rb)
{
	int temp;
	if (step<0)				//������Ϊ����ʱ�����о������ʹ�ò���Ϊ��
	{
		x=-x;					//xȡ�෴��
		step=-step;			//����ȡ�෴��
		temp=lb;
		lb=-rb;
		rb=-temp;				//�����ұ߽�ȡ�෴�����ҽ���
	}
	//����С��lʹx+l*step>=lb
	if (lb-x>=0)				//��߽�����֪����ұ�
		l=(lb-x+step-1)/step;
	else						//��߽�����֪������
		l=(lb-x)/step;
	//������rʹx+r*step<=rb
	if (rb-x>=0) 				//�ұ߽�����֪����ұ�
		r=(rb-x)/step;
	else						//�ұ߽�����֪������
		r=(rb-x-step+1)/step;
	return;
}
//��ax+by=c��lx<=x<=rx��ly<=y<=ryʱ������ĸ���
int cal(int a,int b,int c,int lx,int rx,int ly,int ry)
{
	long long x,y,dx,dy,l1,r1,l2,r2;
	int d;
	d=egcd(abs(a),abs(b),x,y);	//ʹ����չŷ������㷨
	if (c%d!=0)					//�����ڽ�����
		return 0;
	if (a<0)						//���aΪ����������Ӧ����x
		x=-x;
	if (b<0) 						//���bΪ����������Ӧ����y
		y=-y;
	x*=c/d;						//�������һ�����xֵ
	y*=c/d;						//�������һ�����yֵ
	dx=b/d;						//x�ı仯����
	dy=-a/d;						//y�ı仯����
	cal_bound(x,dx,l1,r1,lx,rx);//ͨ��x��t�����ұ߽�
	cal_bound(y,dy,l2,r2,ly,ry);//ͨ��y��t�����ұ߽�
	if (l1<l2)					//ȡ��߽�����ֵ
		l1=l2;
	if (r1>r2)					//ȡ�ұ߽����Сֵ
		r1=r2;
	return r1-l1+1;				//���ؽ�ĸ���
}
int init()						//Ԥ������
{
	int i,j,temp;
	for(i=1;i<maxn;i++){		//ö�پ��ε�����һ�߳�
		for(j=1;j<maxn;j++){	//ö�پ��ε���һ�߳�
			temp=cal(2*i,-2*j,i*i-j*j,0,i,0,j);//�������(1)�Ľ��
			if (i==j)				//������Ϊ������ʱ���������ظ�������һ��
				temp--;
			if (temp>0)
				f[i][j]+=temp;	//���Ϸ����ۼӵ�f������
			temp=cal(2*i,2*j,i*i+j*j,1,i-1,1,j-1);//�������(2)�Ľ��
			if (i%2==0&&j%2==0)	//��ȥ�������Ϊ0�����
				temp--;
			if (temp>0)
				f[i][j]+=temp;	//���Ϸ����ۼӵ�f������
			//��f���鵽g�����ת�Ʒ���
			g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1]+f[i][j];
			//��g���鵽h�����ת�Ʒ���
			h[i][j]=h[i-1][j]+h[i][j-1]-h[i-1][j-1]+g[i][j];
		}
	}
	return 0;
}

int main()
{
	int m,n;
	init();								//Ԥ����
	while(scanf("%d%d",&m,&n)!=EOF){	//��������m,nֱ���ļ�����
		printf("%I64d\n",h[m][n]);		//�����
	}
	return 0;
}
