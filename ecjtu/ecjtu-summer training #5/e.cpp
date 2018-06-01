/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
const double Inf = 1e-9;
const int MAX = 10100;
struct Nod{
	double ll;
	double rr;
}nod[MAX];
bool cmp(Nod a, Nod b){
	return a.ll < b.ll;
}
int main(){
	double n,l,w;
	double x,r;
	while(scanf("%lf %lf %lf",&n,&l,&w)!=EOF){
		int k = 0;
		for(int i = 0; i < n; i ++){
			scanf("%lf %lf",&x,&r);
			if(r*2<=w){
				continue;
			}else{
				double xx = sqrt(r*r-w*w/4.0);
				nod[k].ll = x-xx;
				nod[k].rr = x+xx;
				k++;
			}
		}
		sort(nod,nod+k,cmp);
	/*	for(int i = 0; i < k; i ++){
			printf("%.2lf   %.2lf\n",nod[i].ll,nod[i].rr);
		}*/
		int ans = 0, i = 0;
		double pos = 0,righ=0;
		if(nod[0].ll <= 0){
			while(i < k){
				int j = i;
				//printf("%.2lf %.2lf\n",nod[j].ll,pos);
				while(j < k && nod[j].ll <= pos){
					if(nod[j].rr > righ)
						righ = nod[j].rr;
					j++;
				}
				if(i == j)break;
				pos = righ;
				i=j;ans++;
				if(pos>=l)break;
			}
		}
		if(pos >= l){
			printf("%d\n",ans);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
*/



/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 1e4+10;
struct Nod{
	int ll, rr;
}nod[MAX];
bool cmp(Nod a, Nod b){
	if(a.ll != b.ll) return a.ll < b.ll;
	else return a.rr > b.rr;
}
int main(){
	double n,l,w;
	while(scanf("%lf %lf %lf",&n,&l,&w)!=EOF){
		double r,x,k = 0;
		for(int i = 0; i < n; i ++){
			scanf("%d %d",&x,&r);
			if(2*r < w)continue;
			nod[k].ll = x-r;
			nod[k++].rr = x+r;
		}
		sort(nod,nod+k,cmp);
		int pos = 0, i = 0, ans = 0;
		while(pos < l && i < k){
			if(nod[i].ll > pos)break;
			if(pos > nod[i].rr){
				i++;continue;
			}
			if(i+1 < k && nod[i+1].ll <= pos && nod[i+1].rr > nod[i].rr){
				i++;continue;
			}
			ans++;
			pos = nod[i++].rr;
		}
		if(pos < l){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
}*/