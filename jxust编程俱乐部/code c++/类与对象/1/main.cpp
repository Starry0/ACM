#include <iostream>

using namespace std;
class time{
public:
    int hour;
    int minute;
    int sec;
};
time t;
void set_time(void){
    cin>>t.hour>>t.minute>>t.sec;
}
void show_time(void){
    cout<<t.hour<<':'<<t.minute<<':'<<t.sec<<endl;
}
int main()
{
    set_time();
    show_time();
    return 0;
    return 0;
}
