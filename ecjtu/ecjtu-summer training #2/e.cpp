    #include<iostream>  
    #include<cstdio>  
    #include<cstring>  
    #include<string>  
    using namespace std;  
    int m, n, ex, ey, k, p[105][105];  
    //p[x][y]代表某位置  
    char map1[105][105];  
    int x_move[4] = {-1, 0, 1, 0};  
    int y_move[4] = {0, 1, 0, -1};  
    bool flag;  
      
void dfs(int x, int y, int dir){
	if(x == ex && y == ey){
		if(p[x][y] <= k)
			flag = true;
		return;
	}
	if((p[x][y] > k) || (p[x][y] == k && x != ex && y != ey))
		return;
	for(int i = 0; i < 4; i ++){
		int xx = x+x_move[i], yy = y+y_move[i];
		if(xx < 0 || xx >= m || yy < 0 || yy >= n)
			continue;
		if(map1[xx][yy] == '*' || p[xx][yy] < p[x][y])
			continue;
		if(dir!=-1 && i != dir)
			p[xx][yy] = p[x][y] + 1;
		else p[xx][yy] = p[x][y];
		dfs(xx,yy,i);
		if(flag)return;
	}
	
	
}  
      
    int main()  
    {  
        int t,i,j,sx,sy; //sx， sy是起点  
        scanf ("%d", &t);  
        while (t--)  
        {  
            scanf("%d%d",&m,&n);  
            for(i=0;i<m;i++)  
                scanf ("%s",map1[i]);  
            scanf("%d%d%d%d%d",&k,&sy,&sx,&ey,&ex);  
            sx--,sy--,ex--,ey--;  //从0开始编号，而题目是从1开始  
            for (i = 0; i < m; i++)  
                for (j = 0; j < n; j++)  
                    p[i][j] = 10005; //初始化转弯数为无穷大  
            p[sx][sy] = 0; //到达起点的转弯数  
            flag = false;  
            dfs (sx, sy, -1); //一开始可以走任意方向，所以设方向为-1  
            if (flag) puts ("yes");  
            else puts ("no");  
        }  
        return 0;  
    }  