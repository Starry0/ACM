#include <iostream>
#include <cstring>
using namespace std;
struct student{
    char number;
    string name;
    float score[3];
};
int main()
{
    int N,m;
    cin>>N;
    student stu[N];
    for(int i=0;i<N;i++){
        cin>>stu[i].number>>stu[i].name>>stu[i].score[0]>>stu[i].score[1]>>stu[i].score[2];
    }
    float MAX=(stu[0].score[0]+stu[0].score[1]+stu[0].score[2]);m=0;
    float average[3];
    average[0]=average[1]=average[2]=0;
    for(int i=0;i<N;i++){
        average[0]+=stu[i].score[0]/N;
        average[1]+=stu[i].score[1]/N;
        average[2]+=stu[i].score[2]/N;
        if(MAX<(stu[i].score[0]+stu[i].score[1]+stu[i].score[2]))m=i;
    }
    cout<<average[0]<<' '<<average[1]<<' '<<average[2]<<endl;
    cout<<stu[m].number<<' '<<stu[m].name<<' '<<stu[m].score[0]<<' '<<stu[m].score[1]<<' '<<stu[m].score[2]<<endl;
    return 0;
}
