#include<stdio.h>
#include<string.h>
int main()
{
	void swap(char *,char *);
	char str1[20],str2[20],str3[20];
	scanf("%s%s%s",str1,str2,str3);
	if(strcmp(str1,str2)>0) swap(str1,str2);
	if(strcmp(str1,str3)>0) swap(str1,str3);
	if(strcmp(str2,str3)>0) swap(str2,str3);
	printf("%s\n%s\n%s\n",str1,str2,str3);
	return 0;
}
void swap(char *p1,char *p2)
{
	char p[20];
	strcpy(p,p1);strcpy(p1,p2);strcpy(p2,p);
}
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	void swap(char *,char *);
	char str1[20],str2[20],str3[20];
	cin>>str1>>str2>>str3;
	if(strcmp(str1,str2)>0) swap(str1,str2);
	if(strcmp(str1,str3)>0) swap(str1,str3);
	if(strcmp(str2,str3)>0) swap(str2,str3);
	cout<<str1<<endl<<str2<<endl<<str3;
	return 0;
}
void swap(char *p1,char *p2)
{
	char p[20];
	strcpy(p,p1);strcpy(p1,p2);strcpy(p2,p);
}
