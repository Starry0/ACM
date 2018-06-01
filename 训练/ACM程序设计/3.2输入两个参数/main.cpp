#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream cin("in.txt");
    int a,b;
    while(cin>>a>>b){
        cout<<a-b<<endl;
    }
    return 0;
}
