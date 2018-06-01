#include <iostream>
#include <cstdio>
using namespace std;
void move(char x, char y);
void f(int n, char a, char b, char c){
    if(n == 1)
        move(a, c);
    else{
        f(n-1,a,c,b);
        move(a,c);
        f(n-1,b,a,c);
    }
}
void move(char x, char y){
    static int i = 1;
    printf("%d:%c->%c\n",i++,x,y);
}
int main(){
    int n;
    cin >> n;
    f(n, 'A', 'B','C');
    return 0;
}
