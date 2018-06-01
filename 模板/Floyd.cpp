int d[MAX_N]d[MAX_N];
int v;

void Floyd(){
    for(int k = 0; k < v; k ++){
        for(int i = 0; i < v; i ++){
            for(int j = 0; j < v; j ++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
}