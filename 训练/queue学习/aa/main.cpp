#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct p{
    int a,b,t;
    bool operator < (const p &a)const{
        return t > a.t;
    }
};
int main(){

    priority_queue<p> q;
    return 0;
}
