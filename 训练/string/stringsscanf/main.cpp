#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string s1,s2,s3;
    char sa[100],sb[100],sc[100];
    //���ַ�����������֣��ָ���Ϊ�ո�
    sscanf("abc 123 pc","%s %s %s",sa,sb,sc);
    s1=sa;s2=sb;s3=sc;
    cout<<s1<<' '<<s2<<' '<<s3<<endl;
    //���ַ�����������֣��ָ���Ϊ�ո�
    //���õ����ֵ�ʱ�򣬸�scanfһ������Ҫ��ָ���ַ
    int a,b,c;
    sscanf("1 2 3","%d %d %d",&a,&b,&c);
    cout<<a<<' '<<b<<' '<<c<<endl;
    //���ַ�����������֣��ָ���Ϊ','��'$'
    //���õ����ֵ�ʱ�򣬸�scanfһ������Ҫ��ָ���ַ
    int x,y,z;
    sscanf("4,5$6","%d,%d$%d",&x,&y,&z);
    cout<<x<<' '<<y<<' '<<z<<endl;
    return 0;
}
