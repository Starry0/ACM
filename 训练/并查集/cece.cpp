#include <cstdio>
#include <map>
using namespace std;
const int maxn=10010 ;
int f[maxn],r[maxn] ;
void init ()
{
    for (int i=0 ; i<maxn ; i++){
        f[i] = i ;
        r[i] = 0 ;
    }
}
int find (int x)
{
    if (f[x]==x){
        return x ;
    }
    int root = find(f[x]) ;
    r[x] = (r[x]+r[f[x]])%2 ;
    f[x] = root ;
    return f[x] ;
}
int Union (int x,int y,int d)
{
    int a = find(x) ;
    int b = find(y) ;
    if (a==b){
        if ((r[x]+r[y]+d)%2==0){
            return 1 ;
        }
        else return 0 ;
    }
    else{
        f[a] = b ;
        r[a] = (r[x]+r[y]+d)%2 ;
        return 1 ;
    }
}
int main()
{
    char s[5] ;
    int n,m ;
    scanf("%d%d",&n,&m) ;
    init() ;
    map <int,int> hash ;
    int i,a,b,add=0,d ;
    for (i=1 ; i<=m ; i++){
        scanf("%d %d %s",&a,&b,s) ;
        a-- ;
        if (hash.find(a)==hash.end()) hash[a] = add++ ;
        int x=hash[a] ;
        if (hash.find(b)==hash.end()) hash[b] = add++ ;
        int y=hash[b] ;
        if (s[0]=='o') d=1 ;
        else d=0 ;
        if (Union(x,y,d)==0) break ;
    }
    printf("%d\n",i-1) ;
    return 0;
}
