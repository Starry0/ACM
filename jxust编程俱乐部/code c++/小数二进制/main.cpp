#include <iostream>
#include <cstdio>
using namespace std;
int num[100];//�����洢2��������ÿһλ
void Change( unsigned int x ) //����ת������
{
 if( x == 0 ) //ע��������
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
