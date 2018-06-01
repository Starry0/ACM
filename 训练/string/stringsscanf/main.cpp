#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string s1,s2,s3;
    char sa[100],sb[100],sc[100];
    //讲字符串分离成数字，分隔符为空格
    sscanf("abc 123 pc","%s %s %s",sa,sb,sc);
    s1=sa;s2=sb;s3=sc;
    cout<<s1<<' '<<s2<<' '<<s3<<endl;
    //将字符串分离成数字，分隔符为空格
    //当用到数字的时候，跟scanf一样，它要传指针地址
    int a,b,c;
    sscanf("1 2 3","%d %d %d",&a,&b,&c);
    cout<<a<<' '<<b<<' '<<c<<endl;
    //将字符串分离成数字，分隔符为','何'$'
    //当用到数字的时候，跟scanf一样，它要传指针地址
    int x,y,z;
    sscanf("4,5$6","%d,%d$%d",&x,&y,&z);
    cout<<x<<' '<<y<<' '<<z<<endl;
    return 0;
}
