#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 505;
const int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
char mat[maxn][maxn];
int n,m;
int sx,sy,ex,ey;
bool judge(int x,int y){
    if(x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}
bool bfs(){
    queue<int>qx,qy;
    qx.push(sx);
    qy.push(sy);
    while(!qx.empty()){
            int x = qx.front(); qx.pop();
            int y = qy.front(); qy.pop();
            for(int i = 0; i < 4; i++){
                    int xx = x + dir[i][0];
                    int yy = y + dir[i][1];
                    if(judge(xx,yy)){
                         if(mat[xx][yy] == 'X'){
                                if(xx == ex && yy == ey)
                                        return true;
                        }
                        else{
                                mat[xx][yy] = 'X';
                                qx.push(xx);
                                qy.push(yy);
                        }
                    }
            }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        scanf("%s",mat[i]);
    }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    sx --; sy--;
    ex --; ey--;
    if(bfs())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
