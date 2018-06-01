#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(3);
    v[0]=2;
    v[1]=7;
    v[2]=9;
    //在最前面插入新元素，元素值为8
    v.insert(v.begin(),8);
    //在第2个元素前插入新元素1
    v.insert(v.begin()+2,1);
    //在向量末尾追加新元素3
    v.insert(v.end(),3);
    //定义迭代器变量
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();++it)
        cout<<*it<<' ';
    cout<<endl;
    return 0;
}
