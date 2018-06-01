#include<iostream>
#include <stdio.h>
#include <map>
using namespace std;
int main()
{
    char str[50],h[50];
    string tp;
    int count=1;
    map<string,string>dic;
    while(true){
        char c;
        if((c=getchar())=='\n')break;
        else
        {
          str[0]=c;
          int i=1;
          while(true)
          {
            c=getchar();
            if(c==' ')
            {
                str[i]='\0';
                break;
            }
            else str[i++]=c;
        }
    }
    scanf("%s",h);
    getchar();
    dic[h]=str;
    count++;
}
    string tar;
    while(cin>>tar)
    {
        map<string,string>::iterator p=dic.find(tar);
        if(p==dic.end())
           printf("%s\n","eh");
        else cout << (*p).second << endl;
    }
    return 0;
}
