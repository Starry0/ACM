#include <stdio.h>
#include <algorithm>
using namespace std;
const int size=100000;				//���������
int a[size],b[size];				//�ֱ𱣴��к����к�
int main(){
	int r,c,i,j;
	long long s,t;					//ö��ʱ�Ƚϵ��к����к�����
	while(scanf("%d%d",&r,&c)==2){//��������r,cֱ���ļ�����
		for(i=0,s=0; i<r; i++){
			scanf("%d",&a[i]);		//�����к�
			s+=a[i];					//�ۼ��к�
		}
		for(i=0,t=0; i<c; i++){
			scanf("%d",&b[i]);		//�����к�
			t+=b[i];					//�ۼ��к�
		}
		if(s!=t){						//����к����к����������
			printf("NO\n");			//�򲻿����н�
			continue;
		}
		sort(a,a+r);					//�к�����
		sort(b,b+c);					//�к�����
		for(i=j=0,t=s=0; i<c; i++){//�Ӵ�Сö���к�
			t+=b[c-i-1];				//��ǰ��ö�ٵ��к�����
			s+=r-j;					//��ǰ���õ��к�����
			while(j<r&&a[j]<i+1){	//���ĳ�к�С��ö������
				s-=i+1-a[j];			//���к�������������Ĳ��ּ�ȥ
				j++;
			}
			if(s<t) break;			//��������к�С�ڵ�ǰ�к��򲻿����н�
		}
		printf(i==c?"YES\n":"NO\n");//�����
	}
	return 0;
}
