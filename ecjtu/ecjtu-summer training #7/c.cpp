// #include<iostream>
// #include<cstdio>
// #include<cmath>
// #include<cstring>
// const int maxn=50000+10;
// using namespace std;
// int p[maxn],a[maxn],f[1000000+10],t=0;
// void prepare(){
// 	int m=(int)sqrt(50000);
// 	for(int i=2;i<=m;i++)
// 		if(!p[i])
// 			for(int j=i*i;j<=50000;j+=i)p[j]=1;
// 	for(int i=2;i<=50000;i++)if(!p[i])a[++t]=i;
// }
// int main(){
// 	prepare();
// 	int L,U;
// 	while(scanf("%d%d",&L,&U)!=EOF){
// 		if(L<2)L=2;
// 		memset(f,0,sizeof(f));
// 		for(int i=1;i<=t;i++){
// 			int s=(L)/a[i],e=U/a[i];
// 			if(L%a[i])s++; 	//这步是必须的，不然会出现j*a[i]-L<0 而出现runtime error
// 			if(s<2)s=2;
// 			for(int j=s;j<=e;j++)f[j*a[i]-L]=1;
// 		}
// 		int p=-1,max_ans=-1,min_ans=1000000000,x1,y1,x2,y2;
//         for(int i=0;i<=U-L;i++){
//             if(f[i]==0){
//                 if(p==-1){p=i;continue;}
//                 if(max_ans<i-p){max_ans=i-p;x1=p+L;y1=i+L;}
//                 if(min_ans>i-p){min_ans=i-p;x2=p+L;y2=i+L;}
//                 p=i;
//             }
//         }
//         if(max_ans==-1)cout<<"There are no adjacent primes."<<endl;
//         else cout<<x2<<","<<y2<<" are closest, "<<x1<<","<<y1<<" are most distant."<<endl;
// 	}
// 	return 0;
// }

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
const int N = 5e5;
const int M = 1e6+10;
int pre[N], f[M], vis[N], t;
void getPri() {
	for(int i = 2; i <= N; i ++) {
		if(!vis[i]) {
			pre[++t] = i;
			for(int j = i+i; j <= N; j += i)
				vis[j] = 1;
		}
	}
}
int main() {
	getPri();
	int L, U;
	while(scanf("%d%d",&L,&U)!=EOF) {
		if(L < 2) L = 2;
		memset(f,0,sizeof(f));
		for(int i = 1; i <= t; i ++) {
			int s = L/pre[i], e = U/pre[i];
			if(L%pre[i]) s++;
			if(s < 2) s = 2;
			for(int j = s; j <= e; j ++)
				f[j*pre[i]-L] = 1;
		}
		int p = -1, Max = -1, Min = 1000000000, x1, x2, y1, y2;
		for(int i = 0; i <= U-L; i ++) {
			if(!f[i]){
				if(p == -1){
					p = i;continue;
				}
				if(i-p > Max){
					Max = i-p; x1 = p+L; y1 = i+L;
				}
				if(i-p < Min) {
					Min = i-p; x2 = p+L; y2 = i+L;
				}
				p = i;
			}
		}
		if(Max == -1) printf("There are no adjacent primes.\n");
		else printf("%d,%d are closest, %d,%d are most distant.\n",x2,y2,x1,y1);
	}
	return 0;
}
