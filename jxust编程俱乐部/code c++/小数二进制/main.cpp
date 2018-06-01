#include <iostream>
#include <cstdio>
using namespace std;
int num[100];//用来存储2进制数的每一位
void Change( unsigned int x ) //进制转化函数
{
 if( x == 0 ) //注意这个情况
 {
printf( "0\n" );
return;
 }

 int k = 0;

 while( x )
 {
num[k++] = x % 2;
x /= 2;
 }

 for( int i = k-1 ; i >= 0 ; i-- )
printf( "%d" , num[i] );
 printf( "\n" );
}
int main()
{
    Change(1.222);
    return 0;
}
