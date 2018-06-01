#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
using namespace std;
//将数值转换为string
string converToString(double x){
    ostringstream o;
    if(o<<x)
        return o.str();
    return "conversion error";
}
//将string 转换为数值
double converfomestring(const string& s){
    istringstream i(s);
    double x;
    if(i>>x)return x;
    return 0.0;//if error
}
int main()
{
    //将数值转换为string的第一种方法：c方法
    char b[10];
    string a;
    sprintf(b,"%d",1975);
    a=b;
    cout<<a<<endl;
    //将数值转换为string的第一种方法：c++方法
    string cc=converToString(1976);
    cout<<cc<<endl;
    //将string转换为数值的方法：c++方法
    string dd="2006";
    int p=converfomestring(dd)+2;
    cout<<p<<endl;
    return 0;
}
