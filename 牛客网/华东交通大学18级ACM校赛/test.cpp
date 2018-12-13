#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e2 + 6 ;
const int MOD = 998244353 ;
int a[AX] ;
LL l , r ;
int k ;
LL dp[AX][8][8] ;
bool check( LL val , int sum ){
	return ( val % 7 == 0 && sum % 7 == 0 ) ;
}

LL dfs( int pos , int sumper , LL val , bool limit ){
	if( pos == -1 ) return check( val , sumper ) ;
	if( !limit && dp[pos][sumper][val] != -1 ) return dp[pos][sumper][val];
	int up = limit ? a[pos] : 9;
	LL ans = 0;
	for( int i = 0 ; i <= up ; i++ ){
		ans += dfs( pos - 1 , (sumper+i)%7 , (val*10+i)%7 , limit && i == up);
	}
	if( !limit ) dp[pos][sumper][val] = ans ;
	return ans ;
}

LL solve( LL x ){
	int tot = 0 ;
	while( x ){
		a[tot++] = x % 10 ;
		x /= 10 ;
	}
	return dfs( tot - 1 , 0 , 0 , true ) ;
}
int main(){
	memset( dp , -1, sizeof(dp) ) ;
	while( ~scanf("%lld%lld",&l,&r) && l && r ){
		LL R = solve(r) ;
		LL L = solve(l-1) ;
		cout << R - L << endl ;
	}
	return 0 ;
}
