#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int>v(10);
    for(int i=0;i<10;i++)
        v[i]=i;
    //�������������Ĵ��׵�β���Ԫ��
    reverse(v.begin(),v.end());
    //�������������
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();++it)
        cout<<*it<<' ';
    cout<<endl;
    return 0;
}
