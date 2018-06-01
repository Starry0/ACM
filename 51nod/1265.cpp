/*
可以由4个点构成3个向量，3个向量共面的充要条件是向量为a，b，c，存在实数x,y,z不全为零，
使得xa+yb+zc=0。转化为线性代数的3个向量线性相关的行列式为0。
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Point{
    int x, y, z;
};

int main(){
    int t;
    scanf("%d",&t);
    while(t--) {
        Point a, b, c, d;
        scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&a.x,&a.y,&a.z,&b.x,&b.y,&b.z,&c.x,&c.y,&c.z,&d.x,&d.y,&d.z);
        a.x = b.x-a.x; a.y = b.y-a.y; a.z = b.z-a.z;
        b.x = c.x-b.x; b.y = c.y-b.y; b.z = c.z-b.z;
        c.x = d.x-c.x; c.y = d.y-c.y; c.z = d.z-c.z;
        if(a.x*b.y*c.z+a.y*b.z*c.x+a.z*b.x*c.y-a.z*b.y*c.x-a.y*b.x*c.z-a.x*b.z*c.y == 0)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
