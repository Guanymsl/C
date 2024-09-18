#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long

using namespace std;

const int N=1e5+5;

ll seg[N*4] , tree[N*4] , ary[N] , d[N];

ll gcd(ll m , ll n){

    if(m==0) return n;
    if(n==0) return m;
    else return (m%n) ? gcd(n , m%n) : n;

}

void build(int l , int r , int cur){

    if(r-l<=1){

        seg[cur] = d[l];
        return;

    }
    else{

        int mid = (l+r)/2;

        build(l,mid,2*cur);
        build(mid,r,2*cur+1);
        
    }

    seg[cur] = gcd(abs(seg[2*cur]),abs(seg[2*cur+1]));

}

void modify(int l , int r , int cur , int ind , ll val){

    if(r-l<=1){

        seg[cur] = seg[cur]+val;
        return;

    }

    int mid = (l+r)/2;

    if(ind<mid) modify(l,mid,2*cur,ind,val);
    else modify(mid,r,2*cur+1,ind,val);
    
    seg[cur] = gcd(abs(seg[2*cur]),abs(seg[2*cur+1]));

}

ll query(int l , int r , int cur , int ql , int qr){

    if(qr<=l||ql>=r) return 0;
    if(qr>=r&&ql<=l) return seg[cur];
    else{

        int mid=(l+r)/2;

        return gcd(abs(query(l,mid,2*cur,ql,qr)),abs(query(mid,r,2*cur+1,ql,qr)));

    }
}

void construct(int l , int r , int cur){

    if(r-l<=1){

        tree[cur] = d[l];
        return;

    }
    else{

        int mid = (l+r)/2;

        construct(l,mid,2*cur);
        construct(mid,r,2*cur+1);
        
    }

    tree[cur] = tree[2*cur]+tree[2*cur+1];

}

void revise(int l , int r , int cur , int ind , ll val){

    if(r-l<=1){

        tree[cur] = tree[cur]+val;
        return;

    }

    int mid = (l+r)/2;

    if(ind<mid) revise(l,mid,2*cur,ind,val);
    else revise(mid,r,2*cur+1,ind,val);
    
    tree[cur] = tree[2*cur]+tree[2*cur+1];

}

ll count(int l , int r , int cur , int ql , int qr){
    if(qr<=l||ql>=r) return 0;
    if(qr>=r&&ql<=l) return tree[cur];
    else{

        int mid=(l+r)/2;

        return count(l,mid,2*cur,ql,qr)+count(mid,r,2*cur+1,ql,qr);

    }
}

int main(){

    IO

    int n , q;

    cin >> n >> q;
    cin >> ary[1];
    d[1] = ary[1];

    for(int i=0; i<=4*n; i++) seg[i]=0 , tree[i]=0;

    for(int i=2; i<=n; i++){

        cin >> ary[i];
        d[i]=ary[i]-ary[i-1];

    }

    build(1,n+1,1);
    construct(1,n+1,1);

    //for(int i=1;i<=4*n;i++) cout<<tree[i]<<" ";

    for(int i=0; i<q; i++){

        int m;
        cin >> m;

        if(m==1){
            
            int l , r;
            ll k;
            cin >> l >> r >> k;

            //d[l] = d[l]+k;
            //d[r+1] = d[r+1]-k;

            modify(1,n+1,1,l,k);
            if(r!=n) modify(1,n+1,1,r+1,-k);

            revise(1,n+1,1,l,k);
            if(r!=n) revise(1,n+1,1,r+1,-k);

            //for(int i=1;i<=4*n;i++) cout<<tree[i]<<" ";

        }

        if(m==2){

            int l , r;
            cin >> l >> r;
            
            //ll num=d[1];
            //cout << count(1,n+1,1,1,l+1)<<'\n';
            cout << gcd(count(1,n+1,1,1,l+1),abs(query(1,n+1,1,l+1,r+1))) << '\n';

        }


    }

    return 0;

}