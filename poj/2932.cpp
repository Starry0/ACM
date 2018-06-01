#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
const int N = 40010;
double x[N], y[N], r[N];
int n;
bool inside(int i, int j) {
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return dx * dx + dy * dy <= r[j] * r[j];
}
void solve() {
    vector<pair<double, int> > events;
    for(int i = 0; i < n; i ++) {
        events.push_back(make_pair(x[i] - r[i], i));
        events.push_back(make_pair(x[i] + r[i], i+n));
    }
    sort(events.begin(), events.end());
    set<pair<double, int> > st;
    vector<int> res;
    for(int i = 0; i < events.size(); i ++) {
        int id = events[i].second % n;
        if(events[i].second < n) {
            set<pair<double, int> > ::iterator it = st.lower_bound(make_pair(y[id], id));
            if(it != st.end() && inside(id, it->second)) continue;
            if(it != st.begin() && inside(id, (--it)->second)) continue;
            res.push_back(id);
            st.insert(make_pair(y[id], id));
        } else {
            st.erase(make_pair(y[id], id));
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n",(int)res.size());
    for(int i = 0; i < res.size(); i ++) {
        printf("%d%c",res[i]+1, i +1 == res.size() ? '\n':' ');
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%lf %lf %lf", &r[i], &x[i], &y[i]);
    }
    solve();
    return 0;
}
