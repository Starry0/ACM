#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int>v(10);
    for(int i=0;i<10;i++)
        v[i]=i;
    //反向排列向量的从首到尾间的元素
    reverse(v.begin(),v.end());
    //定义迭代器变量
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();++it)
        cout<<*it<<' ';
    cout<<endl;
    return 0;
}
