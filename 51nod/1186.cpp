/*
long long 范围的Miller-Rabin素数测试
*/

/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ll long long
using namespace std;

//计算a*b%mod
ll mod_mul(ll a, ll b, ll n){
	ll cnt = 0LL;
	while(b){
		if(b&1LL) cnt = (cnt+a)%n;
		a=(a+a)%n;
		b >>= 1LL;
	}
	return cnt;
}
//计算a^b%mod
ll mod_exp(ll a, ll b, ll n){
	ll res = 1LL;
	while(b){
		if(b&1LL) res = mod_mul(res,a,n);
		a = mod_mul(a,a,n);
		b >>= 1LL;
	}
	return res;
}
//Miller-Rabin测试，测试n是否为素数
bool Miller_Rabin(ll n, int respat){
	if(n==2LL || n==3LL || n==5LL || n==7LL || n==11LL) return true;
	if(n==1 || !(n%2) || !(n%3) || !(n%5) || !(n%7) || !(n%11)) return false;
	
	int k = 0;
	ll d = n-1; //要求x^u%n 不为1一定不是素数
	
	while(!(d&1LL)){
		k++; d >>= 1LL;
	}
	srand((ll)time(0));
	for(int i = 0; i < respat; i ++) {
		ll a = rand()%(n-2)+2; 	//在[2,n)中取整数
		ll x = mod_exp(a,d,n);
		ll y = 0LL;
		for(int j = 0; j < k; j ++){
			y = mod_mul(x,x,n);
			if(1LL==y && 1LL!=x && n-1LL!=x)return false; //二次探测定理，这里如果y = 1则x必须等于 1
														  //或n-1,否则可以判断不是素数
			x = y;
		}
		if(1LL != y) return false;	 //费马小定理
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	if(Miller_Rabin(n,5))cout << "Yes\n";
	else cout << "No\n";
	return 0;
}*/




//
//  main.cpp
//  f-51Nod-1186-质数检测 V2
//
//  Created by ZYJ on 16/8/13.
//  Copyright ? 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAXL 4
#define M10 1000000000
#define Z10 9

const int zero[MAXL - 1] = {0};

struct bnum{
    int data[MAXL]; //  断成每截9个长度
    
    //  读取字符串并转存
    void read(){
        memset(data, 0, sizeof(data));
        char buf[32];
        scanf("%s", buf);
        int len = (int)strlen(buf);
        int i = 0, k;
        while (len >= Z10){
            for (k = len - Z10; k < len; ++k){
                data[i] = data[i] * 10 + buf[k] - '0';
            }
            ++i;
            len -= Z10;
        }
        if (len > 0){
            for (k = 0; k < len; ++k){
                data[i] = data[i] * 10 + buf[k] - '0';
            }
        }
    }
    
    bool operator == (const bnum &x) {
        return memcmp(data, x.data, sizeof(data)) == 0;
    }
    
    bnum & operator = (const int x){
        memset(data, 0, sizeof(data));
        data[0] = x;
        return *this;
    }
    
    bnum operator + (const bnum &x){
        int i, carry = 0;
        bnum ans;
        for (i = 0; i < MAXL; ++i){
            ans.data[i] = data[i] + x.data[i] + carry;
            carry = ans.data[i] / M10;
            ans.data[i] %= M10;
        }
        return  ans;
    }
    
    bnum operator - (const bnum &x){
        int i, carry = 0;
        bnum ans;
        for (i = 0; i < MAXL; ++i){
            ans.data[i] = data[i] - x.data[i] - carry;
            if (ans.data[i] < 0){
                ans.data[i] += M10;
                carry = 1;
            }
            else{
                carry = 0;
            }
        }
        return ans;
    }
    
    //  assume *this < x * 2
    bnum operator % (const bnum &x){
        int i;
        for (i = MAXL - 1; i >= 0; --i){
            if (data[i] < x.data[i]){
                return *this;
            }
            else if (data[i] > x.data[i]){
                break;
            }
        }
        return ((*this) - x);
    }
    
    bnum & div2(){
        int  i, carry = 0, tmp;
        for (i = MAXL - 1; i >= 0; --i){
            tmp = data[i] & 1;
            data[i] = (data[i] + carry) >> 1;
            carry = tmp * M10;
        }
        return *this;
    }
    
    bool is_odd(){
        return (data[0] & 1) == 1;
    }
    
    bool is_zero(){
        for (int i = 0; i < MAXL; ++i){
            if (data[i]){
                return false;
            }
        }
        return true;
    }
};

void mulmod(bnum &a0, bnum &b0, bnum &p, bnum &ans){
    bnum tmp = a0, b = b0;
    ans = 0;
    while (!b.is_zero()){
        if (b.is_odd()){
            ans = (ans + tmp) % p;
        }
        tmp = (tmp + tmp) % p;
        b.div2();
    }
}

void powmod(bnum &a0, bnum &b0, bnum &p, bnum &ans){
    bnum tmp = a0, b = b0;
    ans = 1;
    while (!b.is_zero()){
        if (b.is_odd()){
            mulmod(ans, tmp, p, ans);
        }
        mulmod(tmp, tmp, p, tmp);
        b.div2();
    }
}

bool MillerRabinTest(bnum &p, int iter){
    int  i, small = 0, j, d = 0;
    for (i = 1; i < MAXL; ++i){
        if (p.data[i]){
            break;
        }
    }
    if (i == MAXL){
        // small integer test
        if (p.data[0] < 2){
            return  false;
        }
        if (p.data[0] == 2){
            return  true;
        }
        small = 1;
    }
    if (!p.is_odd()){
        return false;   //  even number
    }
    bnum a, s, m, one, pd1;
    one = 1;
    s = pd1 = p - one;
    while (!s.is_odd()){
        s.div2();
        ++d;
    }
    
    for (i = 0; i < iter; ++i){
        a = rand();
        if (small){
            a.data[0] = a.data[0] % (p.data[0] - 1) + 1;
        }
        else{
            a.data[1] = a.data[0] / M10;
            a.data[0] %= M10;
        }
        if (a == one){
            continue;
        }
        
        powmod(a, s, p, m);
        
        for (j = 0; j < d && !(m == one) && !(m == pd1); ++j){
            mulmod(m, m, p, m);
        }
        if (!(m == pd1) && j > 0){
            return false;
        }
    }
    return true;
}

int main(){
    bnum x;
    
    x.read();
    puts(MillerRabinTest(x, 5) ? "Yes" : "No");
    
    return 0;
}