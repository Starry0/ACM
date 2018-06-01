/*
x+(x+P)+(x+2P)+...+(x+(n-1)P)=s
(s-(P+2P+...+(n-1)P))/n=x
dp[i][j] 前i个元素有j个a的方案数量
我们用二维数组Bo[i][j]来存储背包容量递增，物品按体积1~n的顺序递增时方案数的情况。
i表示有体积为0~i的物品各一个，j表示背包的容量为j。首先要初始化当已有的物品体积数量为0，
也就是相当于只有一个体积为0的物品时，背包容量j为0的方案数为1个，而容量大于0的方案数全为0。
之后来看关键的状态转移方程： Bo[i][j]=Bo[i-1][j] ； i>j Bo[i][j]=Bo[i-1][j]+Bo[i-1][j-i] ； i<=j 
二维数组是从上到下，从左到右进行计算的，每个元素都与之前已经计算过元素相关。第i行j列的元素，
如果i>j，也就是新添加的可选物品的体积大于背包的容积，无法放入背包，所以新添加的可选物品不能够增加方案数。
如果i<=j，新添加的可选物品的体积小于背包的容积，有可能与其他物品组合装入背包，
这时方案数为当没有添加入i体积物品时背包容量为j的方案数Bo[i-1][j]（装入后背包内体积还是小于背包体积），
加上当没有添加入i体积物品时但背包容量恰好可以装入i体积物品的方案数Bo[i][j]=Bo[i-1][j]+Bo[i-1][j-i]（
装入后背包内体积等于背包体积）。这样逐行计算即可知道所有情况下的方案数
*/
#include <bits/stdc++.h>
#define ll long long
#define MOD 100000007
using namespace std;
const int N = 1010;
int dp[2][N*N], e;
ll n, s, a, b;
void DP() {
	dp[e][0] = 1; //前1个
	for(int i = 1; i < n; i ++) {  //前n个元素 注意i < n 不是i <= n
		e = 1 - e;
		for(int j = 0; j <= i*(i+1)/2; j ++) {
			if(i > j) dp[e][j] = dp[1-e][j];
			else dp[e][j] = (dp[1-e][j]+dp[1-e][j-i])%MOD;
		}
	}
}
int main() {
	cin >> n >> s >> a >> b;
	DP();
	ll ans = 0;
	for(ll i = 0; i <= n*(n-1)/2; i ++) {
		ll cnt = s - i*a + (n*(n-1)/2-i)*b;
		if(cnt%n == 0) ans = (ans+dp[e][i])%MOD; 
	}
	cout << ans << endl;
	return 0;
}