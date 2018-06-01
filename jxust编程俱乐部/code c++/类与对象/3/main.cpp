#include <iostream>

using namespace std;
class time{
public:
    void set_time(void);
    void show_time(void);
private:
    int hour;
    int minute;
    int mec;
};
void time::set_time(void){
    cin>>hour>>minute>>mec;
}
void time::show_time(void){
    cout<<hour<<':'<<minute<<':'<<mec<<endl;
}

time t;

int main()
{
    t.set_time();
    t.show_time();
    return 0;
}
