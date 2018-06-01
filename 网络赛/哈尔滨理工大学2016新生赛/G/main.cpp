#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
char nodeType(string s);
void substring(string s);
vector <char> v;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        string s;
        cin >> n;
        while (n<0 || n>10)
        {
            cin >> n;
        }
        cin >> s;
        while (s.size() != pow(2, n))
        {
            cin >> s;
        }

        for (int i=0;i<(int)s.size(); i++)
        {
            if (s[i] == '1')
            {
                s[i] = 'I';
            }
            else if(s[i] == '0')
            {
                s[i] = 'B';
            }
            else
            {
                exit(-1);

            }
        }
        substring(s);
        string temp = "";
        int i;
        for (i=v.size()-1; i>=0; i--)
        {
            temp += v[i];
        }
        cout << temp << endl;
    }
    return 0;
}

void substring(string s)
{
    v.push_back(nodeType(s));
    if (s.size() > 1)
    {
        string s1, s2;
        s1 = s.substr(0, s.size()/2);
        s2 = s.substr(s.size()/2, s.size()/2);
        substring(s2);
        substring(s1);
    }
}
char nodeType(string s)
{
    char type = s[0];
    for (int i=1; i<(int)s.size(); i++)
    {
        if (s[i] != type)
        {
            type = 'F';
            break;
        }
    }

    return type;
}

