#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;
struct Nod{
    int num;
    Nod* next[26];
    Nod(){
        int num = 0;
        for(int i = 0; i < 26; i ++)
            next[i] = NULL;
    }
}t;
int n,m;
char s[11], ss[11];
void mkTrie(char* c){
    Nod* p = &t;
    for(int i = 0; c[i]; i ++){
        int a = c[i]-'a';
        if(p->next[a] == NULL){
            struct Nod* b = (struct Nod*)malloc(sizeof(struct Nod));
            p->next[a] = b;
            //p->next[a] = new Nod;
        }
        p = p->next[a];
        p->num++;
    }
}
int find(char *c){
    Nod* p = &t;
    for(int i = 0; c[i]; i ++){
        int a = c[i]-'a';
        if(p->next[a] == NULL) return 0;
        p = p->next[a];
    }
    return p->num;
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i ++) scanf("%s",s),mkTrie(s);
    scanf("%d",&m);
    while(m--){
        scanf("%s",ss);
        printf("%d\n",find(ss));
    }
    return 0;
}
