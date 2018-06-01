/***********************************
找出输入数据中所有两两相乘的积为12！的个数
************************************/
#include <fstream>
#include <iostream>
#include <set>
using namespace std;
int main(){
    ifstream cin("in.txt");
    int sum =0;
    int f12 = 479001600;
    //多重集合，允许值重复
    multiset<unsigned int>s;
    int n;
    while(cin>>n){
        if(f12%n==0){
            //多重集合中有n的因子吗
            multiset<unsigned int>::iterator it = s.find(f12/n);
            if(it!=s.end()){
                sum++;
                s.erase(it);    //从多重集合中输出该因子
            }
            else s.insert(n);     //插入到多重集合中
        }
    }
    cout<<sum<<endl;
    return 0;
}
