#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

const int N = 3e5 + 5 , H = 16;

typedef pair<int , int> pii;

struct E{

    int v;
    int u;
    int w;

    bool operator<(const E& e)const{
        return w < e.w;
    }

};

vector<E> edge;
vector<pii> MST[N];

int dsu[N];
int fa[N][H] , mx[N][H];
int tin[N] , tout[N];

int query(int x){

    if(dsu[x] == x) return x;

    dsu[x] = query(dsu[x]);
    return dsu[x];

}

void dfs(int cur , int father){

    static int t = 0;

    t++;
    tin[cur] = t;

    int temp = father;
    for(int i=0; i<H; i++){

        fa[cur][i] = temp;

        if(i < H - 1) mx[cur][i + 1] = max(mx[cur][i] , mx[temp][i]);

        temp = fa[temp][i];

    }

    for(int i=0; i<(int)MST[cur].size(); i++){

        if(MST[cur][i].ff != father) mx[MST[cur][i].ff][0] = MST[cur][i].ss , dfs(MST[cur][i].ff , cur);

    }

    t++;
    tout[cur] = t;

}

bool isfa(int a , int b){ return tin[a] <= tin[b] && tout[a] >= tout[b]; }

int lca(int a , int b){

    int ti = 0;

    if(isfa(b , a)) swap(a , b);
    else if(!isfa(a , b)){

        for(int i=H-1; i>=0; i--){

            if(!isfa(fa[a][i] , b)){

                ti = max(ti , mx[a][i]);
                a = fa[a][i];

            }

        }

        ti = max(ti , mx[a][0]);
        a = fa[a][0];

    }

    for(int i=H-1; i>=0; i--){

        if(!isfa(fa[b][i] , a)){

            ti = max(ti , mx[b][i]);
            b = fa[b][i];

        }

    }

    ti = max(ti , mx[b][0]);

    return ti;

}

int main(){

    IO

    int v , e;
    cin >> v >> e;

    for(int i=1; i<=v; i++){

        dsu[i] = i;
        tin[i] = 0;

        for(int j=0; j<H; j++) mx[i][j] = 0;

    }

    for(int i=0; i<e; i++){

        int x , y , d;
        cin >> x >> y >> d;

        edge.pb((E){x , y , d});

    }

    sort(edge.begin() , edge.end());

    for(int i=0; i<e; i++){

        int V = edge[i].v , U = edge[i].u , W = edge[i].w;
        int P = query(V) , Q = query(U);

        if(P != Q){

            dsu[P] = Q;

            MST[V].pb(mp(U , W));
            MST[U].pb(mp(V , W));

        }

    }

    for(int i=1; i<=v; i++) if(!tin[i]) dfs(i , i);

    int q;
    cin >> q;

    for(int i=0; i<q; i++){

        int st , ed;
        cin >> st >> ed;

        if(st == ed) cout << 0 << '\n';
        else if(query(st) != query(ed)) cout << -1 << '\n';
        else{

            int ans = lca(st , ed);
            cout << ans << '\n';

        }

    }

    return 0;

}