#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    s="cat dog cat";
    //s�ȡ�cat���ַ����󣬷�������
    cout<<s.compare("cat")<<endl;
    //s�롰cat dog cat ����ȣ�����0��
    cout<<s.compare("cat dog cat")<<endl;
    //s�ȡ�dog��С������-1
    cout<<s.compare("dog")<<endl;
    return 0;
}
