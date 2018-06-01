// #include<iostream>
// #include<cstdio>
// #include<map>
// #include<string>
// using namespace std;
// int f[200000];
// int w[200000];
// int find(int x)
// {
// 	if(f[x]==x)return x;
// 	else{
// 		int r=find(f[x]);
// 		w[x]^=w[f[x]];
// 		return f[x]=r;
// 	}
// }
// void join(int a,int b,int W)
// {
// 	int F=find(a);
// 	w[F]=w[a]^W;
// 	f[F]=b;
// }
// int main()
// {
// 	int n,m,q,temp;
// 	map<string,int> M;
// 	string t,a,b;
// 	cin>>n>>m>>q;
// 	for(int i=1;i<=n;i++){
// 		cin>>t;
// 		M[t]=i;
// 		f[i]=i;
// 	}
// 	for(int i=1;i<=m;i++){
// 		scanf("%d",&temp);
// 		cin>>a>>b;
// 		int A=M[a],B=M[b];
// 		if(find(A)!=find(B)){
// 			cout<<"YES"<<endl;
// 			join(A,B,temp-1);
// 		}
// 		else{
// 			if(w[A]^w[B]==(temp-1))
// 				cout<<"YES"<<endl;
// 			else
// 				cout<<"NO"<<endl;
// 		}
//
// 	}
// 	for(int i=1;i<=q;i++){
// 		cin>>a>>b;
// 		int A=M[a],B=M[b];
// 		if(find(A)!=find(B))
// 			cout<<3<<endl;
// 		else{
// 			cout<<(w[A]^w[B])+1<<endl;
// 		}
// 	}
// 	return 0;
// }


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
const int N = 2e5+10;
int fa[N*2];
int find(int x){
    return fa[x] = fa[x]==x?x:find(fa[x]);
}
int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x > y) fa[x] = y;
    else fa[y] = x;
}
int main(){
    int n,m,q;
    string s, ss;
    for(int i = 1; i <= N*2-1; i ++) fa[i] = i;
    scanf("%d%d%d",&n,&m,&q);
    map<string,int> mp;
    for(int i = 1; i <= n; i ++) {
        cin>>s;
        mp[s] = i;
    }
    int num;
    for(int i = 1; i <= m; i ++) {
        cin>>num>>s>>ss;
        if(num == 1){
            int x = find(mp[s]);
            int y = find(mp[ss]+N);
            if(x == y) printf("NO\n");
            else {
                printf("YES\n");
                unite(mp[s],mp[ss]);
                unite(mp[s]+N,mp[ss]+N);
            }
        } else {
            int x = find(mp[s]);
            int y = find(mp[ss]);
            //printf("%d  %d  \n",x,y);
            if(x == y) printf("NO\n");
            else{
                printf("YES\n");
                unite(mp[s],mp[ss]+N);
                unite(mp[s]+N,mp[ss]);
            }
        }
    }
    while(q--) {
        cin>>s>>ss;
        if(find(mp[s]) == find(mp[ss]))printf("1\n");
        else if(find(mp[s]) == find(mp[ss]+N)) printf("2\n");
        else printf("3\n");
    }
    return 0;
}
