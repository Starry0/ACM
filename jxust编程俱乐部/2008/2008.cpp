#include <bits/stdc++.h>
using namespace std;
struct DATE{
    double d;
    int num;
    int p;
}date[11];
bool cmp(DATE a,DATE b){
    return a.d<b.d;
}
int main(){
    for(int i=1;i<11;i++){
        cin>>date[i].p;
        date[i].num=i;
        date[i].d=(double)date[i].p/i;
    }
    sort(date+1,date+11,cmp);
    int ans,b,k=1,price=0;
    cin>>ans;
    while(ans>0){
        b=ans/date[k].num;
        price+=b*date[k].p;
        ans-=b*date[k].num;
        k++;
    }
    cout<<price<<endl;
    return 0;
}
