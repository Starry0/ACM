#include <iostream>
using namespace std;
int a[11], n;
int main(){
    cin >> n;
    while(n--){
        for(int i = 0; i < 10; i ++) cin >> a[i];
        int c = 0, b = 0, flag = 1;
        for(int i = 0; i < 10; i ++){
            if(c > b){
                if(a[i] > c){
                    c = a[i];
                }else if(a[i] > b){
                    b = a[i];
                }else{
                    flag = 0;
                }
            }else{
                if(a[i] > b){
                    b = a[i];
                }else if(a[i] > c){
                    c = a[i];
                }else{
                    flag = 0;
                }
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}


#include <iostream>
using namespace tsd;
int a[11];
int main(){
    int n;
    cin >> n;
    while(n--){
        for(int i = 1; i <= 10; i ++) cin >> a[i];


    }
    return 0;
}
