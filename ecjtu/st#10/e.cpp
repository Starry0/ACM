// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <algorithm>
// #define ll long long
// using namespace std;
// const int MAX = 100000;
// struct Nod{
//     Nod* nex[11];
//     int id;
//     Nod(){
//         for(int i = 0; i < 10; i ++)
//             nex[i] = NULL;
//             id = -1;
//     }
// }t;
// string s,ss;
// void mkTrie(char* s, int id){
//     Nod *p = &t;
//     for(int i = 0; s[i]; i ++){
//         int x = s[i] - '0';
//         if(p->nex[x] == NULL){
//             p->nex[x] = new Nod;
//         }
//         p = p->nex[x];
//         if(p->id == -1)
//             p->id = id;
//     }
// }
// int find(char *s){
//     Nod *p = &t;
//     for(int i = 0; s[i]; i ++) {
//         int x = s[i] - '0';
//         if(p->nex[x] == NULL) return -1;
//         p = p->nex[x];
//     }
//     return p->id;
// }
void add(char *a, char *b, char *c) {
    int i = strlen(a)-1;
    int j = strlen(b)-1;
    int k = 0, up = 0, x, y, z;
    while(i >= 0 || j >= 0) {
        if(i < 0) x = 0;
        else x = a[i] -'0';
        if(y < 0) y = 0;
        else y = b[j] - '0';
        z = x+y+up;
        c[k++] = z%10+'0';
        up = z/10;
        i--;j--;
    }
    if(up > 0) c[k++] = up + '0';
    for(i = 0; i < k/2; i ++)
        swap(c[i],c[k-i-1]);
    c[k] = '\0';
}
// char str[3][100];
void init() {
    str[0][0] = '1';str[0][1] = '\0';
    str[1][0] = '1';str[1][1] = '\0';
    mkTrie(str[0],0);mkTrie(str[1],1);
    for(int i = 2; i < 100000; i ++){
        int len1 = strlen(str[0]);
        int len2 = strlen(str[1]);
        if(len2 > 60) {
            str[1][len2-1] = '\0';
            str[0][len1-1] = '\0';
        }
        add(str[0],str[1],str[2]);
        mkTrie(str[2],i);
        strcpy(str[0],str[1]);
        strcpy(str[1],str[2]);
    }
}

// int main() {
//     std::ios::sync_with_stdio(false);
//     init();
//     int t;
//     scanf("%d",&t);
//     for(int i = 1; i <= t; i ++) {
//         char ss[60];
//         scanf("%s",ss);
//         printf("Case #%d: %d\n",i,find(ss));
//     }
//     return 0;
// }


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
const int MAX = 2e5+10;
struct Nod{
    Nod* nex[11];
    int id;
    Nod(){
        for(int i = 0; i < 10; i ++)
            nex[i] = NULL;
            id = -1;
    }
}t;
string s,ss;
void mkTrie(string s, int id){
    Nod *p = &t;
    for(int i = 0; i < s.length(); i ++){
        int x = s[i] - '0';
        if(p->nex[x] == NULL){
            p->nex[x] = new Nod;
        }
        p = p->nex[x];
        if(p->id == -1)
            p->id = id;
    }
}
int find(char* s){
    Nod *p = &t;
    for(int i = 0;s[i]; i ++) {
        int x = s[i] - '0';
        if(p->nex[x] == NULL) return -1;
        p = p->nex[x];
    }
    return p->id;
}
string add(string s, string ss) {
    reverse(s.begin(),s.end());
    reverse(ss.begin(),ss.end());
    int flag = 0;
    if(s.length() > ss.length()){
        swap(s,ss);
    }
    int len1 = s.length(), len2 = ss.length();
    string sss = "";
//    cout << ss << ' ' << s << endl;
    for(int i = 0; i < len2; i ++){
        int b = ss[i] - '0', a;
        if(i < len1){
            a = s[i] - '0';
        }else a = 0;
        int c = a+b+flag;
        if(c > 9){
            sss += c-10+'0';
            flag = 1;
        }else {
            sss += c +'0';
            flag = 0;
        }
    }
    if(flag) sss += '1';
    reverse(sss.begin(),sss.end());
    return sss;
}
void init() {
    s = "1"; ss = "1";
    mkTrie(s,0);mkTrie(ss,1);
    for(int i = 2; i < 100000; i ++){
        if(s.length() > 100){
            reverse(s.begin(),s.end());
            reverse(ss.begin(),ss.end());
            s = s.substr(50,1000);
            ss = ss.substr(50,1000);
            reverse(s.begin(),s.end());
            reverse(ss.begin(),ss.end());
        }
        string sss = add(s,ss);
        mkTrie(sss,i);
        s = ss;
        ss = sss;
    }
}

int main() {
    //std::ios::sync_with_stdio(false);
    init();
    int t;
    scanf("%d",&t);
    for(int i = 1; i <= t; i ++) {
        char s[60];//这里一定要用字符数组，用string就会答案错误。不知道怎么一回事。
        scanf("%s",s);
        printf("Case #%d: %d\n",i,find(s));
    }
    return 0;
}
