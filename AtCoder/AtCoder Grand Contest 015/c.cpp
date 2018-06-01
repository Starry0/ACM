#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+10;
char a[N][N];
int vectex[N][N], edgeH[N][N], edgeW[N][N];

int main(){
    int n, m, q;
    scanf("%d %d %d\n",&n,&m,&q);
    for(int i = 0; i < n; i ++){
        scanf("%s",a[i]);
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            vectex[i+1][j+1] = (a[i][j] == '1') + vectex[i+1][j] + vectex[i][j+1] -vectex[i][j];
            edgeH[i+1][j+1] = (a[i+1][j] == '1' && a[i][j] == '1') + edgeH[i+1][j] + edgeH[i][j+1] - edgeH[i][j];
            edgeW[i+1][j+1] = (a[i][j+1] == '1' && a[i][j] == '1') + edgeW[i+1][j] + edgeW[i][j+1] - edgeW[i][j];
        }
    }
    while(q--){
        int x1, x2, y1, y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1--;y1--;
        int vec = vectex[x2][y2] - vectex[x2][y1] - vectex[x1][y2] + vectex[x1][y1];
        int edg = edgeH[x2-1][y2] - edgeH[x2-1][y1] - edgeH[x1][y2] + edgeH[x1][y1] +
                    edgeW[x2][y2-1] - edgeW[x2][y1] - edgeW[x1][y2-1] + edgeW[x1][y1];
        printf("%d\n",vec - edg);
    }
    return 0;
}
