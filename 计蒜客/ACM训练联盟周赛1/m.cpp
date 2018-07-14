#include <bits/stdc++.h>
using namespace std;
const int AX = 1e5+66;
int lazy[AX<<2], s[AX<<2], a[AX], op[AX], l[AX], r[AX], n,k,tot;

void pushDown( int rt , int L , int R ){
    if( lazy[rt] != -1 ){
        int mid = ( L + R ) >> 1 ;
        s[rt<<1] = ( mid - L + 1 ) * lazy[rt] ;
        s[rt<<1|1] = ( R - mid ) * lazy[rt];
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = -1;
    }
    return ;
}


void pushUp( int rt ){
    s[rt] = s[rt<<1] + s[rt<<1|1];
    return ;
}

void build( int l , int r , int rt , int v ){
    lazy[rt] = -1;
    if( l == r ){
        s[rt] =  ( a[l] > v ) ;
        return ; 
    }
    int mid = ( l + r ) >> 1 ;
    build( l , mid , rt << 1 , v );
    build( mid + 1 , r , rt << 1 | 1 , v);
    pushUp(rt);
}

void update( int L , int R , int v , int l , int r , int rt ){
    if( L <= l && R >= r ){
        s[rt] = v * ( r - l + 1 );
        lazy[rt] = v;
        return;
    }
    pushDown(rt,l,r);
    int mid = ( l + r ) >> 1;
    if( L <= mid ) update( L , R , v , l , mid , rt << 1 );
    if( R > mid ) update( L , R , v , mid + 1 , r , rt << 1 | 1);
    pushUp(rt);
}

int query( int L , int R , int l , int r , int rt ){
    if( L <= l && R >= r ){
        return s[rt];
    }
    pushDown(rt,l,r);
    int ans = 0 ;
    int mid = ( l + r ) >> 1;
    if( L <= mid ) ans += query( L , R , l , mid, rt << 1 );
    if( R > mid )  ans += query( L , R , mid + 1, r , rt << 1 | 1 );
    return ans ;
}

int main(){
    int m ;
    scanf("%d%d%d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&a[i]);
    }
    for( int i = 0 ; i < m ; i++ ){
        scanf("%d%d%d",&l[i],&r[i],&op[i]);     
    }
    int li = 1 , ri = n ; 
    while( li < ri ){
        int mid = ( li + ri ) >> 1 ;
        build( 1 , n , 1 , mid );
        for( int i = 0 ; i < m ; i++ ){
            int L = l[i];
            int R = r[i];
            int c = query( L , R , 1 , n , 1 );
            update( L , R , 0 , 1 , n , 1 );
            if( op[i] ){  
                if( L <= L + c - 1 ){
                    update( L , L + c - 1 , 1 , 1, n , 1 );
                } 
            }else{
                if( R - c + 1 <= R ){
                    update( R - c + 1 , R , 1 , 1 , n , 1 );
                }
            }
        }
        if( query( k , k , 1 , n , 1 ) ){
            li = mid + 1 ;
        }else ri = mid  ;
    }
    printf("%d\n",li);
    return 0 ;
}