#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
		vector<string> vs, vs1, vs2;
        for(int i = 1; i < S.length()-2; i ++) {
			string s,ss;
			s = S.substr(1,i);
			ss = S.substr(i+1,S.length()-i-2);
			if(s.length() == 1) vs1.push_back(s);
			else{
				for(int j = 1; j <= s.length(); j ++) {
					string s1, s2;
					s1 = s.substr(0,j);
					s2 = s.substr(j,s.length());
					if(s1.length()>=2&&s1[0]=='0')continue;
					if(s2.length()>=2&&s2[s2.length()-1]=='0')continue;
					if(j == s.length()) {
						vs1.push_back(s1);
						continue;
					}
					int ans = 0;
					for(int k = 0; k < s2.length(); k ++) {
						if(s2[k] == '0') ans++;
					}
					if(ans == s2.length()) continue;
					vs1.push_back(s1+"."+s2);
				}
			}
			if(ss.length() == 1) vs2.push_back(ss);
			else{
				for(int j = 1; j <= ss.length(); j ++) {
					string ss1, ss2;
					ss1 = ss.substr(0,j);
					ss2 = ss.substr(j,ss.length());
					if(ss1.length()>=2&&ss1[0]=='0')continue;
					if(ss2.length()>=2&&ss2[ss2.length()-1]=='0')continue;
					if(j == ss.length()) {
						vs2.push_back(ss1);
						continue;
					}
					int ans = 0;
					for(int k = 0; k < ss2.length(); k ++) {
						if(ss2[k] == '0') ans++;
					}
					if(ans == ss2.length()) continue;
					vs2.push_back(ss1+"."+ss2);
				}
			}
			//cout << s << ' ' << ss << endl;
		}
		for(int i = 0; i < vs1.size(); i ++) {
			for(int j = 0; j < vs2.size(); j ++) {
				int ans1 = 0;
				if(vs1[i].find(".") != string::npos) ans1 = 1;
				if(vs2[j].find(".") !=  string::npos) ans1++;
				if(vs1[i].length()+vs2[j].length() == S.length()-2+ans1) {
					vs.push_back("("+vs1[i]+", "+vs2[j]+")");	
					//cout << "("+vs1[i]+", "+vs2[j]+")" << endl;
				}
			}
		}
		return vs;
    }
};

int main() {
	Solution sol;
	sol.ambiguousCoordinates("(0010)");
	return 0;
}