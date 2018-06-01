#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

string strmultiply(string str1,string str2) {
	string strresult="";
	int a[1000]={0};
	int len1=str1.length();
	int len2=str2.length();
	int i,j;
	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++) {
			a[len1-1-i+len2-1-j]+=(str1[i]-'0')*(str2[j]-'0');
		}
	
	for(i=0;i<len1+len2;i++) {
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	for(i=len1+len2-1;i>=0;i--) {
		if(0!=a[i]) break;
	} 
	for(j=i;j>=0;j--)
	strresult+=(a[j]+'0');
	return strresult;
}

int compare(string str1,string str2,int pos) {
	int len1=str1.length();
	int len2=str2.length();
	if(len2>len1+pos) return 0;
	if(len2<len1+pos) return 1;
	int i;
	for(i=0;i<len2;i++) {
		if(str1[i]>str2[i]) return 1;
		if(str1[i]<str2[i]) return 0;
	}
	return 0;
}

string sqrtlarge(string str) {
	int len=str.length();
	string str1="";
	string strresult="";
	int i,j;
	
	if(len%2==0) {
		for(i=0;i<len/2;i++)
			for(j=0;j<10;j++) {
				str1=strresult;
				str1+=(j+'0');
				if(compare(strmultiply(str1,str1),str,2*(len/2-i-1))==1) {
					strresult+=(j-1+'0');
					break;
				}
				if(j==9) strresult+='9';
			}
	} else {
		for(i=0;i<len/2+1;i++)
		for(j=0;j<10;j++) {
			str1=strresult;
			str1+=(j+'0');
			if(compare(strmultiply(str1,str1),str,2*(len/2-i))==1) {
				strresult+=(j-1+'0');
				break;
			}
			if(j==9) strresult+='9';
		}
	}
	return strresult;
}
int main() {
	string str1,str2;
	cin>>str1>>str2;
	cout<<strmultiply(sqrtlarge(str1),sqrtlarge(str2))<<endl;
	return 0;
} 