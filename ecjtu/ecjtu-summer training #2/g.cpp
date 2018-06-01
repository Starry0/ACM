#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
int n,m,gx,gy,p[110][110],k;
int dx[] = {1,0,-1,0},dy[] = {0,-1,0,1};
char str[110][110];
bool flag;

void dfs (int x, int y, int dir)  {  
    if (x == gx && y == gy)  {  
        if (p[x][y] <= k)  
            flag = true;  
        return ;  
    }  
    if ((x !=gx && y != gy && p[x][y] == k)||p[x][y]>k)  
        return ;  
    for (int i = 0; i < 4; i++)  {  
        int tx = x + dx[i];  
        int ty = y + dy[i];  
        if (tx < 0 || tx >= m|| ty < 0 || ty >= n)  
            continue;  
        if (str[tx][ty] == '*' || p[tx][ty] < p[x][y])  
            continue;  
        if (dir != -1 && i != dir && p[tx][ty] == p[x][y] )  
            continue;          
        if (dir != -1 && i != dir)  
            p[tx][ty]=p[x][y]+1; 
        else p[tx][ty] = p[x][y];  
        dfs (tx, ty, i);  
        if (flag) return ;  
    }  
}  

int main(){
	int t,qx,qy;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		for(int i = 0; i < m; i ++)
			scanf("%s",str[i]);
		scanf("%d%d%d%d%d",&k,&qy,&qx,&gy,&gx);
		qx--;qy--;gx--;gy--;
		for(int i = 0; i < 110; i ++)
			for(int j = 0; j < 110; j ++)
				p[i][j] = 100000;
		p[qx][qy] = 0;
		flag = false;
		dfs(qx,qy,-1);
		if(flag)puts("yes");
		else puts("no");
	}
	return 0;
} 