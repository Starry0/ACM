#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 8;
int a[N][N] = {0};
void Print(){
    static int ans = 1;
    printf("Case %d:\n",ans++);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%c ",a[i][j]?'Q':'.');
        }
        printf("\n");
    }
    printf("\n");
}
bool Safety(int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j]&&(j==col||abs(row-i)==abs(col-j)))
                return false;
        }
    }
    return true;
}
void BlackTrack(int i){
    if(i >= N){
        Print();
        return;
    }
    else{
        for(int j = 0; j < N; j++){
            a[i][j] = 1;
            if(Safety(i,j)){
                BlackTrack(i+1);
            }
            a[i][j] = 0;
        }
    }
}
int main(){
    BlackTrack(0);
    return 0;
}
