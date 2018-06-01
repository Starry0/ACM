#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

int main(){
    int tmp;
    for( int i = 0; i < 5; i++){
        cin >> tmp;
        q.push(tmp);
    }
    cout << "队的大小：" << q.size() << endl;
    cout << "队头的值为：" << q.front() <<endl;
    cout << "队尾的值为：" << q.back() <<endl;
    cout << "---------" << endl;
    while( !q.empty()){
        cout << q.front() <<endl;
        q.pop();
    }
    return 0;
}
