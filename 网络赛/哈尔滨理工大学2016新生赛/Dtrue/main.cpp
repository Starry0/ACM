#include <stdio.h>
#include <algorithm>
using namespace std;
const int size=100000;				//最大行列数
int a[size],b[size];				//分别保存行和与列和
int main(){
	int r,c,i,j;
	long long s,t;					//枚举时比较的行和与列和总数
	while(scanf("%d%d",&r,&c)==2){//输入整数r,c直到文件结束
		for(i=0,s=0; i<r; i++){
			scanf("%d",&a[i]);		//输入行和
			s+=a[i];					//累加行和
		}
		for(i=0,t=0; i<c; i++){
			scanf("%d",&b[i]);		//输入列和
			t+=b[i];					//累加列和
		}
		if(s!=t){						//如果行和与列和总数不相等
			printf("NO\n");			//则不可能有解
			continue;
		}
		sort(a,a+r);					//行和排序
		sort(b,b+c);					//列和排序
		for(i=j=0,t=s=0; i<c; i++){//从大到小枚举列和
			t+=b[c-i-1];				//当前已枚举的列和总数
			s+=r-j;					//当前可用的行和总数
			while(j<r&&a[j]<i+1){	//如果某行和小于枚举列数
				s-=i+1-a[j];			//把行和总数多算出来的部分减去
				j++;
			}
			if(s<t) break;			//如果可用行和小于当前列和则不可能有解
		}
		printf(i==c?"YES\n":"NO\n");//输出答案
	}
	return 0;
}
