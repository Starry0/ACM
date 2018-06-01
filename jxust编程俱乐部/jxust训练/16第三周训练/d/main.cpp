#include<iostream>
#include<algorithm>
using namespace std;
int a[110];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a+1, a + n+1);
  int i = 1, j = n, ans = 0;
  while (i <= j) {
    if (i == j) {
      ans++;
      break;
    } else if ((a[i] + a[j]) <= 4) {
      if (i != (j - 1)) {
        if ((a[i] + a[j] + a[j - 1]) <= 4) {
          if (i != (j - 2)) {
            if ((a[i] + a[j] + a[j - 1] + a[j - 2]) <= 4) {
              i++;
              j = j - 3;
              ans++;
            } else {
              ans++;
              i++;
              j = j - 2;
            }
          } else {
            ans++;
            break;
          }
        } else {
          ans++;
          i++;
          j--;
        }
      } else {
        ans++;
        break;
      }
    } else {
      ans++;
      j--;
    }
  }
  cout << ans << endl;
  return 0;
}
