/*
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
using namespace std;
int n;
char str[100];
map<char,int> mp;
map<int,int> mp1;
void init() {
	mp['A'] = mp['B'] = mp['C'] = 2;
	mp['D'] = mp['E'] = mp['F'] = 3;
	mp['G'] = mp['H'] = mp['I'] = 4;
	mp['J'] = mp['K'] = mp['L'] = 5;
	mp['M'] = mp['N'] = mp['O'] = 6;
	mp['P'] = mp['R'] = mp['S'] = 7;
	mp['T'] = mp['U'] = mp['V'] = 8;
	mp['W'] = mp['X'] = mp['Y'] = 9;
}
int main() {
	init();
	cin >> n;
	while(n--) {
		memset(str,0,sizeof(str));
		//cin >> str;
		scanf("%s",str);
		int ans = 0;
		for(int i = 0; str[i]; i ++) {
			if(str[i] != '-') {
				ans*=10;
				if('0' <= str[i] && str[i] <= '9') ans += str[i] - '0';
				else ans += mp[str[i]];
			}
		}
		mp1[ans]++;
	}
	map<int,int> :: iterator it = mp1.begin();
	bool flag = false;
	for(; it != mp1.end(); ++ it) {
		if((*it).second > 1) {
			flag = true;
			printf("%03d-%04d %d\n",(*it).first/10000,(*it).first%10000,(*it).second);
		}
	}
	if(!flag) printf("No duplicates.\n");
	return 0;
}
*/
#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	//std::ios::sync_with_stdio(false);
    int a[26] = {0};
    int numberBit = 2;
    int stringCnt = 0;
    int phoneNum = 0;
    int resultFlag = 0;
    int index = 0;
    string  phoneString;
    string phoneOnlyNumbers;
    string hyphens = "-";
    std::map <string, int> stringLinkNumber;
    for (int i = 0; i < 26; i++)
    {
        if ((16 == i) || ((25 == i)))
        {
            continue;
        }
        else
        {
            a[i] = numberBit;
            stringCnt++;
            if (3 == stringCnt)
            {
                numberBit++;
                stringCnt = 0;
                continue;
            }
        }
    }
    cin >> phoneNum;
    if (phoneNum > 100000)
    {
        cout << "No duplicates." << endl;
    }

    for (int i = 0; i < phoneNum; i++)
    {
        phoneString == "";
        phoneOnlyNumbers = "";
        cin >> phoneString;
        for (int j = 0; j < phoneString.size(); j++)
        {
            if ('-' == phoneString[j])
            {
                continue;
            }
            else
            {
                if ((phoneString[j] >= 'A') && ((phoneString[j] <= 'Z')))
                {
                    index = phoneString[j] - 'A';
                    phoneOnlyNumbers += a[index] + '0';
                }
                else
                {
                    phoneOnlyNumbers += phoneString[j];
                }
            }
        }

        phoneOnlyNumbers.insert(3,"-");
        ++stringLinkNumber[phoneOnlyNumbers];
    }

    std::map<string,int>::iterator it = stringLinkNumber.begin();
    for (; it != stringLinkNumber.end(); it++)
    {
        std::pair<string,int> _p = *it;
        if (1 < _p.second)
        {
            std::cout <<_p.first<<" "<< _p.second<< endl;
            resultFlag = 1;
        }
    }
    if (0 == resultFlag)
    {
        cout << "No duplicates." << endl;
    }
    return 0;
}