#include <iostream>

using namespace std;
void MOVE(char x,char y){
    static int i=1;
    cout<<i++<<":"<<x<<"->"<<y<<endl;
}
void hannoi(int n,char A,char B,char C){
    if(n==1)MOVE(A,C);
    else {
        hannoi(n-1,A,C,B);
        MOVE(A,C);
        hannoi(n-1,B,A,C);
    }
}
int main()
{
    char A='A',B='B',C='C';
    int n;
    cin>>n;
    hannoi(n,A,B,C);
    return 0;
}
