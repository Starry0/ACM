#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    s="123456";
    string::iterator it;
    it=s.begin();
    //���ַ�'p'���뵽��1���ַ�ǰ��ע�⣬�ַ�λ���Ǵ�0��ʼ������
    s.insert(it+1,'p');
    cout<<s<<endl;
    return 0;
}
//��������1p23456
