#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int a[30], b[30], tot1, tot2, c[30];
struct Nod {
	int id, num;
	Nod() {
		id = num = -1;
	}
}e[30];
struct Nod1 {
	int a,b,c;
}E[20];
bool cmp(Nod A, Nod B) {
	return A.num < B.num;
}
bool seven() {
	if(a[0]==a[1]&&a[1]!=a[2]&&a[2]==a[3]&&a[3]!=a[4]&&a[4]==a[5]&&a[5]!=a[6]) {
		if(a[6]==a[7]&&a[7]!=a[8]&&a[8]==a[9]&&a[9]!=a[10]&&a[10]==a[11]&&a[11]!=a[12]&&a[12]==a[13]) return true; 
	}
	return false;
}
bool ok1() {
	for(int i = 1; i <= 27; i ++) {
		while(b[i]&&b[i+1]&&b[i+2]) {
			E[tot2].a = i;
			E[tot2].b = i+1;
			E[tot2++].c = i+2;
			b[i]--;
			b[i+1]--;
			b[i+2]--;
		}
		if(b[i] == 3) {
			e[tot1].id = i;
			e[tot1++].num = 3;
		}
		if(b[i] == 2) {
			e[tot1].id = i;
			e[tot1++].num = 2;
		}
	}
	if(tot1+tot2 != 5) return false;
	sort(e,e+tot1,cmp);
	if(e[0].num == 2 && e[1].num != 2) return true;
	else return false; 
}
bool ok2() {
	for(int i = 0; i < tot1; i ++) {
		if(e[i].id==1||e[i].id==9||e[i].id==10||e[i].id==18||e[i].id==19||e[i].id==27) return false;
	}
	for(int i = 0; i < tot2; i ++) {
		if(E[i].a==1||E[i].a==9||E[i].a==10||E[i].a==18||E[i].a==19||E[i].a==27) return false;
		if(E[i].b==1||E[i].b==9||E[i].b==10||E[i].b==18||E[i].b==19||E[i].b==27) return false;
		if(E[i].c==1||E[i].c==9||E[i].c==10||E[i].c==18||E[i].c==19||E[i].c==27) return false;
	}
	return true;
}
bool ok3() {
	for(int i = 0; i < tot1; i ++) {
		if(e[i].id!=1&&e[i].id!=9&&e[i].id!=10&&e[i].id!=18&&e[i].id!=19&&e[i].id!=27) return false;
	}
	for(int i = 0; i < tot2; i ++) {
		if(E[i].a!=1&&E[i].a!=9&&E[i].a!=10&&E[i].a!=18&&E[i].a!=19&&E[i].a!=27) 
		if(E[i].b!=1&&E[i].b!=9&&E[i].b!=10&&E[i].b!=18&&E[i].b!=19&&E[i].b!=27)
		if(E[i].c!=1&&E[i].c!=9&&E[i].c!=10&&E[i].c!=18&&E[i].c!=19&&E[i].c!=27) return false;
	}
	return true;
}
bool ok4() {
	if(tot2==4 && tot1 == 1) return true;
	else return false;
}
bool ok5() {
	int ans1 = 0, ans2 = 0;
	memset(b, 0, sizeof(b));
	for(int i = 0; i < 14; i ++) b[a[i]]++;
	for(int i = 1; i <= 27; i ++) {
		if(b[i] == 2) ans1++;
		if(b[i] == 3) ans2++;
	}
	if(ans1 == 1 && ans2 == 4) return true;
	else return false;
}
bool four() {
	if(!ok1()) return false;
	printf("%d %d\n",tot1,tot2 );
	for(int i = 0; i < tot1; i ++) printf("%d %d\n",e[i].id,e[i].num);
	for(int i = 0; i < tot2; i ++) printf("%d %d %d\n",E[i].a,E[i].b,E[i].c );
	if(ok2()||ok3()||ok4()||ok5()) return true;
	else return false;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		tot1 = tot2 = 0;
		for(int i = 0; i < 14; i ++) {
			cin >> a[i];
			b[a[i]]++;
		}
		sort(a, a+14);
		if(seven() || four()) printf("1\n");
		else printf("0\n");
	}
	return 0;
}