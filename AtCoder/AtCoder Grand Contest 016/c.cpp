#include <bits/stdc++.h>
#define ll long long
using namespace std;
int H, W, h, w;

int main(){
	cin >> H >> W >> h >> w;	
	if((H/h)*(W/w)*(1000*(h*w-1)+1)>1000*(H*w-(H/h)*(W/w)))	
		cout << "No\n";
	else{
		cout << "Yes\n";
		for(int i = 1; i <= H; i ++){
			for(int j = 1; j <= W; j ++){
				if(i%h==0&&j%w==0) 
					cout << -1000*(h*w-1)-1 << ' ';
				else cout << 1000 << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}