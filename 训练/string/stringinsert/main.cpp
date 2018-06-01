#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    s="123456";
    string::iterator it;
    it=s.begin();
    //把字符'p'插入到第1个字符前（注意，字符位置是从0开始计数）
    s.insert(it+1,'p');
    cout<<s<<endl;
    return 0;
}
//输出结果是1p23456
