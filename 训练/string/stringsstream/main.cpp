#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
using namespace std;
//����ֵת��Ϊstring
string converToString(double x){
    ostringstream o;
    if(o<<x)
        return o.str();
    return "conversion error";
}
//��string ת��Ϊ��ֵ
double converfomestring(const string& s){
    istringstream i(s);
    double x;
    if(i>>x)return x;
    return 0.0;//if error
}
int main()
{
    //����ֵת��Ϊstring�ĵ�һ�ַ�����c����
    char b[10];
    string a;
    sprintf(b,"%d",1975);
    a=b;
    cout<<a<<endl;
    //����ֵת��Ϊstring�ĵ�һ�ַ�����c++����
    string cc=converToString(1976);
    cout<<cc<<endl;
    //��stringת��Ϊ��ֵ�ķ�����c++����
    string dd="2006";
    int p=converfomestring(dd)+2;
    cout<<p<<endl;
    return 0;
}
