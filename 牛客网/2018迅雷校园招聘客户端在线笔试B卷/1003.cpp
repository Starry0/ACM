#include <bits/stdc++.h>
using namespace std;
struct A {
	int a;
	char b;
	int c;
	char d;
};
struct P {
	struct A w[2];
	short b;
	struct A* p;
};
int main() {
	cout << sizeof(P) << endl;
	return 0;
}