#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 2e5 + 66 ;
int a[AX] ;
map<int,int>mp;
int main(){
	int n ;
	scanf("%d",&n) ;
	int x ;
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d",&x) ;
		mp[x] ++ ;
	}
	int cnt = 0 ;
	for( auto t : mp ){
		a[cnt++] = t.second ;
	}
	LL res = 0 ;
	sort( a , a + cnt ) ;
	for( int i = 1 ; i <= a[cnt-1] ; i++ ){
		int tmp = i ;
		LL temp = i ;
		int st = lower_bound( a , a + cnt , tmp ) - a ;
		while(1){
			if( st + 1 >= cnt ) break;
			int pos = lower_bound( a + st + 1 , a + cnt , 2 * tmp ) - a ;
			if( pos < 0 || pos >= cnt ) break ;
			temp += 2 * tmp ;
			tmp *= 2 ;
			st = pos ;
		}
		res = max( res , temp ) ;
	}
	cout << res << endl;
	return 0 ;
}
