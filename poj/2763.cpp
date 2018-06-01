#include <iostream>
#include <stdio.h>
#include <vectot>
#include <string.h>
using namespace std;
const int N = 100011;
struct Nod{
    int id, to, cost;
};
int n, q, s;
int type[N];
int x[N], t[N];
vector<Nod> G[N];
int root;

int main(){
    scanf("%d%d%d",&n,&q,&s);
    root = n/2;
    for(int i = 0; i < n-1; i ++){
        int a, b, w;
        scanf("%d%d%d",&a,&b,&w);
        G[a-1].push_back((Nod){i,b-1,w});
        G[b-1].push_back((Nod){i,a-1,w});
    }
    init(n);

    return 0;
}
