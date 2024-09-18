#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long

using namespace std;

const int N=1e6+5;

ll cyc[N];

ll cnt(ll n){

    if(n>1e4){

        if(n%2==1) return cnt(n*3+1)+1;
        else return cnt(n/2)+1;

    }

    if(cyc[n]!=0) return cyc[n];

    if(n%2==1){

        cyc[n] = cnt(n*3+1)+1;
        return cyc[n];

    }else{

        cyc[n] = cnt(n/2)+1;
        return cyc[n];

    }

}

int main(){

    IO
    
    for(int i=0; i<N; i++) cyc[i]=0;
    cyc[1]=1;

    for(ll i=2; i<=N; i++){

        if(cyc[i]==0) cyc[i] = cnt(i);

    }

    //for(int i=1;i<=N;i++) cout<<cyc[i]<<" ";

    int l , r;

    while(cin >> l >> r){

        int L = l , R = r;
        if(l>r) swap(L,R);

        ll ans = 0;

        for(int i=L; i<=R; i++) ans = max(ans,cyc[i]);

        cout << l << " " << r << " " << ans << '\n';

    }

    return 0;

}