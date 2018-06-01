#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 2e5+10;
int score[maxn];
int main(){
    int n,m;
    while( ~scanf("%d%d", &n, &m) ){
        memset(score, 0, sizeof(score));
        char c;
        int a, b, maxn = - 10000;
        for(int i = 1; i <= n; i++)
            scanf("%d", & score[i]);
        //getchar();
        for(int i = 0; i < m; i++){
            //scanf("%c%d%d", &c, &a, &b);
            //getchar();
            cin>>c>>a>>b;
          //  cout << score[4] <<' '<< score[5] <<endl;
            if(c == 'Q'){
                for(int j = a; j <= b; j++){
                    if( score[j] > maxn)
                        maxn = score[j];
                }
                    //maxn = max(maxn, score[j]);
                printf("%d\n",maxn);
                maxn = -10000;
            }
            if (c == 'U'){
                score[a] = b;
            }
        }
    }
    return 0;
}
