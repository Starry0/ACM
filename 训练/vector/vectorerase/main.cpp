#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(10);
    for(int i=0;i<10;i++)
        v[i]=i;
    //ɾ���ڶ���Ԫ�أ���2��ʼ����
    v.erase(v.begin()+2);
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();++it)
        cout<<*it<<' ';
    cout<<endl;
    //ɾ����������1����5���������Ԫ��      v[1]��v[4]ɾ��
    v.erase(v.begin()+1,v.begin()+5);
    for(it=v.begin();it!=v.end();++it)
        cout<<*it<<' ';
    cout<<endl;
    //�������
    v.clear();
    cout<<v.size()<<endl;
    return 0;
}
