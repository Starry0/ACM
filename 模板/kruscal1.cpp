/*
最小生成树
*/

struct Nod{
    int l, r, w;
}edg;
bool operator < (Nod a, Nod b){
    return a.w > b.w;
}
int find(int x){
    return fa[x] = (fa[x] == x) ? x : find(fa[x]);
}
int kruscal(){
    int sum = 0;
    while(que.size()){
        edg = que.top();
        que.pop();
        int a = find(edg.l);
        int b = find(edg.r);
        if(a != b){
            fa[a] = b;
            sum += edg.w;
        }
    }
    return sum;
}
