#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
char str[50],str1[50];

struct Nod{
	char str[50];
	Nod*next[26];
	Nod(){
		for(int i = 0; i < 26; i ++){
			next[i] = NULL;
		}
	}
}t;

void mkTrie(char *s, char *ss){
	Nod *p = &t;
	for(int i = 0; ss[i]; i ++){
		int a = ss[i] - 'a';
		if(p->next[a]==NULL){
			p->next[a] = new Nod;
		}
		p = p->next[a];
	}
	strcpy(p->str,s);
}

void find(char *s){
	Nod *p = &t;
	for(int i = 0; s[i]; i ++){
		int a = s[i]-'a';
		if(p->next[a] ==NULL){
			puts("eh");
			return;
		}
		p = p->next[a];
	}
	puts(p->str);
}
int main(){
	char c;
	while(1){
		if((c=getchar())=='\n')break;
		str[0] = c;
		int i = 1;
		while(1){
			if((c=getchar())==' ')break;
			str[i++] = c;
		}
		str[i] = '\0';
		i = 0;
		while(1){
			if((c=getchar())=='\n')break;
			str1[i++] = c;
		}
		str1[i] = '\0';
		mkTrie(str,str1);
	}
	while(scanf("%s",str)!=EOF){
		find(str);
	}
	return 0;
}