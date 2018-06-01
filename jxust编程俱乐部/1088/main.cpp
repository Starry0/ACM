#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int a, b, c;
    int w = 0;
    string name;
    while (cin >> a >> b >> c) {
        set<string> s;
        vector<string> v;
        for (int i=0; i<a; i++) {
            cin >> name;
      //      cout << ++w <<endl;
            s.insert(name);
        }
        for (int j=0; j<b; j++) {
            cin >> name;
      //      cout << ++w <<endl;
            if (s.count(name)) v.push_back(name);
        }
        for (int k=0; k<c; k++) {
            cin >> name;
        //    cout << ++w <<endl;
            for (int i=0; i<v.size(); i++) {
                if (v[i] == name) {
                    v.erase(v.begin()+i);
                }
            }
        }
        if (v.empty()) cout << "No enemy spy\n";
        else {
            int sz = v.size();
            cout << v[0];
            for (int i=1; i<sz; i++)
                cout << " " << v[i];
            cout << "\n";
        }
    }
    return 0;
}
