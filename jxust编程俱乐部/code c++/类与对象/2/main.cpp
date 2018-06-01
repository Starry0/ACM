#include <iostream>

using namespace std;
class time{
public:
    void set_time(){
        cin>>hour>>minute>>mec;
    }
    void show_time(){
        cout<<hour<<':'<<minute<<':'<<mec<<endl;
    }
private:
    int hour;
    int minute;
    int mec;
};
time t;
int main()
{
    t.set_time();
    t.show_time();
    return 0;
}
