#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(3);
    v[0]=2;
    v[1]=7;
    v[2]=9;
    //����ǰ�������Ԫ�أ�Ԫ��ֵΪ8
    v.insert(v.begin(),8);
    //�ڵ�2��Ԫ��ǰ������Ԫ��1
    v.insert(v.begin()+2,1);
    //������ĩβ׷����Ԫ��3
    v.insert(v.end(),3);
    //�������������
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();++it)
        cout<<*it<<' ';
    cout<<endl;
    return 0;
}
