#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
		for(int i = 0; i < paragraph.length(); i ++) {
			if(!isalpha(paragraph[i])) paragraph[i] = ' ';
			if(paragraph[i] >= 'A' && paragraph[i] <= 'Z') paragraph[i] += 32;
		}
        map<string,int> mp;
		string s, ss;
		istringstream sss(paragraph);
		while(sss >> s) {
		//	cout << s << endl;
			bool flag = false;
			for(int i = 0; i < banned.size(); i ++) {
				if(s == banned[i]) flag = true;
			}
			if(!flag) {
				mp[s]++;
			}
		}
		map<string,int>::iterator it = mp.begin();
		int MAX = 0;
		for(; it != mp.end(); it++) {
			if((*it).second > MAX) {
				MAX = (*it).second;
				ss = (*it).first;
			}
		}
		for(int i = 0; i < ss.length(); i ++) {
			if(ss[i] >= 'A' && ss[i] <= 'Z') ss[i] += 32;
		}
		return ss;
	}
};

int main() {
	string s = "Bob. hIt, ball";
	vector<string> vs;
	vs.push_back("hit");
	vs.push_back("bob");
	Solution sol;
	cout << sol.mostCommonWord(s,vs) << endl;
	return 0;
}