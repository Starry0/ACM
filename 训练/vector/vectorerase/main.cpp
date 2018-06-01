#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(10);
    for(int i=0;i<10;i++)
        v[i]=i;
    //删除第二个元素，从2开始计数
    v.erase(v.begin()+2);
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();++it)
        cout<<*it<<' ';
    cout<<endl;
    //删除迭代器第1到第5区间的所有元素      v[1]到v[4]删除
    v.erase(v.begin()+1,v.begin()+5);
    for(it=v.begin();it!=v.end();++it)
        cout<<*it<<' ';
    cout<<endl;
    //清空向量
    v.clear();
    cout<<v.size()<<endl;
    return 0;
}
