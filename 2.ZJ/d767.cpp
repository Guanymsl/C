#include <iostream>
#include <vector>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

const int N = 3e5 + 5 , H = 19;

vector<int> G[N];
int tin[N] , tout[N] , par[N][H] , d[N];
int n;

void print(){

    for(int i=1; i<=n; i++) cout << i << " ";
    cout << '\n';

    for(int i=1; i<=n; i++) cout <<  tin[i] << " ";
    cout << '\n';

    for(int i=1; i<=n; i++) cout << tout[i] << " ";
    cout << '\n';

    for(int i=1; i<=n; i++) cout << d[i] << " ";
    cout << '\n';

    for(int i=1; i<=n; i++){

        for(int j=0; j<=log2(n); j++) cout << par[i][j] << " ";
        cout << '\n';

    }

    cout << '\n';

}

void build(int cur , int p , int depth){

    //print();

    static int cnt = 0;

    cnt++;
    tin[cur] = cnt;

    d[cur] = depth;

    int temp = p;
    for(int i=0; i<=log2(n); i++) par[cur][i] = temp , temp = par[temp][i];

    for(int i=0; i<(int)G[cur].size(); i++){

        if(G[cur][i] != p) build(G[cur][i] , cur , depth + 1);

    }

    cnt++;
    tout[cur] = cnt;

}

bool isanc(int v , int u){

    return tin[v] <= tin[u] && tout[v] >= tout[u];

}

int query(int a , int b){

    if(isanc(a , b)) return a;
    if(isanc(b , a)) return b;

    for(int i=log2(n); i>=0; i--){

        if(!isanc(par[a][i] , b)) a = par[a][i];

    }

    return par[a][0];

}

int main(){

    IO

    int q;
    cin >> n >> q;

    for(int i=1; i<=n; i++){

        int son;

        while(cin >> son && son) G[i].pb(son) , G[son].pb(i);

    }

    build(1 , 1 , 0);

    for(int i=0; i<q; i++){

        int a , b;
        cin >> a >> b;

        int ans = query(a , b);

        cout << ans << " " << d[a] + d[b] - 2 * d[ans] << '\n';

    }

    return 0;

}