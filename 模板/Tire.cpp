/*字典树
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
char str[20];
bool flag;
struct Nod{
    bool is;
    Nod *next[26];
    Nod(){
        is = false;
        for(int i = 0; i < 26; i ++){
            next[i] = NULL;
        }
    }
};
void mkTrie(Nod *root,char *s){
    Nod*p = root;
    for(int i = 0; s[i]; i ++){
        int a = s[i] - '0';
        if(p->next[a]==NULL)p->next[a] = new Nod;
        if(p->is){
            flag = true;
        }
        p = p->next[a];
    }
    p->is = true;
    for(int i = 0; i < 26; i ++){
        if(p->next[i]!=NULL){
            flag = true;
            break;
        }
    }
}
void deleTrie(Nod *p){
    if(p == NULL) return;
    for(int i = 0; i < 26; i ++){
        if(p->next[i] != NULL){
            deleTrie(p->next[i]);
        }
    }
    free(p);
    return ;
}
int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        Nod *t = new Nod;
        flag = false;
        for(int i = 0; i < n; i ++){
            scanf("%s",str);
            if(!flag){
                mkTrie(t,str);
            }
        }
        if(flag)cout << "NO\n";
        else cout << "YES\n";
        deleTrie(t);
    }
    return 0;
}















/*
数组实现
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int sum[100000*26][26], sz = 1,n, m, trie[100000*26];
char s[11];

void mkTrie(){
    int root = 0;
    for(int i = 0; s[i]; i ++){
        int a = s[i]-'a';
        if(!sum[root][a]) sum[root][a] = sz++;
        trie[root]++;
        root = sum[root][a];
    }
    trie[root]++;
}
int find(){
    int root = 0;
    for(int i = 0; s[i]; i ++){
        int a = s[i] - 'a';
        if(sum[root][a])root=sum[root][a];
        else return 0;
    }
    return trie[root];
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        scanf("%s",s);
        mkTrie();
    }
    scanf("%d",&m);
    while(m--){
        scanf("%s",s);
        printf("%d\n",find());
    }
    return 0;
}