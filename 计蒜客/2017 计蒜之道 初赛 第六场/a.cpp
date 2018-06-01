#include <bits/stdc++.h>
using namespace std;
int main(){
	int d;
	cin>>d;
	if(d < 20){
		cout << "+-----+\n|    E|\n|     |\n|     |\n|     |\n|     |\n+-----+\n" << endl;
	}else if(d < 40){
		cout << "+-----+\n|-   E|\n|     |\n|     |\n|     |\n|     |\n+-----+\n"<< endl;
	}else if(d < 60){
		cout << "+-----+\n|-   E|\n|--   |\n|     |\n|     |\n|     |\n+-----+\n"<< endl;
	}else if(d < 80){
		cout << "+-----+\n|-  3G|\n|--   |\n|---  |\n|     |\n|     |\n+-----+\n"<< endl;
	}else if(d < 90){
		cout << "+-----+\n|-  3G|\n|--   |\n|---  |\n|---- |\n|     |\n+-----+\n"<< endl;
	}else if(d < 100){
		cout << "+-----+\n|-  4G|\n|--   |\n|---  |\n|---- |\n|     |\n+-----+\n"<< endl;
	}else if(d == 100){
		cout << "+-----+\n|-  4G|\n|--   |\n|---  |\n|---- |\n|-----|\n+-----+\n"<< endl;
	}
	return 0;
}