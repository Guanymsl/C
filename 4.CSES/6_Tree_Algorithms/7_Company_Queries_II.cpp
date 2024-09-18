#include <iostream>
#include <vector>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

const int N = 2e5 + 5 , H = 18;

vector<int> G[N];
int tin[N] , tout[N] , par[N][H];
int n;

void print(int* arr){

    for(int i=1; i<=n; i++) cout << arr[i] << " ";
    cout << '\n';

}

void build(int cur , int parent){

    static int time = 0;

    time++;
    tin[cur] = time;

    int temp = parent;
    for(int i=0; i<=log2(n); i++) par[cur][i] = temp , temp = par[temp][i];

    for(int i=0; i<(int)G[cur].size(); i++){

        if(G[cur][i] != parent) build(G[cur][i] , cur);

    }

    time++;
    tout[cur] = time;

}

bool ispar(int a , int b){

    return tin[a] <= tin[b] && tout[a] >= tout[b];

}

int lca(int a , int b){

    if(ispar(a , b)) return a;
    if(ispar(b , a)) return b;

    for(int i=log2(n); i>=0; i--) if(!ispar(par[a][i] , b)) a = par[a][i];

    return par[a][0];

}

int main(){

    int q;
    cin >> n >> q;

    for(int i=2; i<=n; i++){

        int boss;
        cin >> boss;

        G[i].pb(boss);
        G[boss].pb(i);

    }

    build(1 , 1);

    //print(tin);
    //print(tout);

    for(int i=0; i<q; i++){

        int a , b;
        cin >> a >> b;

        cout << lca(a , b) << '\n';

    }

    return 0;

}