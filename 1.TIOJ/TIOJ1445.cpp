#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

const int N = 1e3 + 5 , H = 13;

typedef long long ll;
typedef pair<int , ll> pil;

struct E{

    int v;
    int u;
    ll w;

    bool operator<(const E& e) const{ return w < e.w; }

};

int dsu[N];
int tin[N] , tout[N];
int fa[N][H];
ll mx[N][H];

vector<pil> G[N] , MST[N];
vector<E> edge;

ll minll(ll a , ll b){

    if(a <= b) return a;
    return b;

}

ll maxll(ll a , ll b){

    if(a >= b) return a;
    return b;

}

int query(int x){

    if(dsu[x] == x) return x;

    dsu[x] = query(dsu[x]);
    return dsu[x];

}

void dfs(int cur , int father){

    static int t = 0;

    t++;
    tin[cur] = t;

    for(int i=0 , temp=father; i<H; i++){

        fa[cur][i] = temp;

        if(i < H - 1) mx[cur][i + 1] = maxll(mx[cur][i] , mx[temp][i]);

        temp = fa[temp][i];

    }

    for(int i=0; i<(int)MST[cur].size(); i++){

        if(MST[cur][i].ff != father) mx[MST[cur][i].ff][0] = MST[cur][i].ss , dfs(MST[cur][i].ff , cur);

    }

    t++;
    tout[cur] = t;

}

bool isfa(int a , int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }

ll lca(int a , int b){

    ll mxx = 0;

    if(isfa(b , a)) swap(a , b);
    else if(!isfa(a , b)){

        for(int i=H-1; i>=0; i--){

            if(!isfa(fa[a][i] , b)){

                mxx = maxll(mxx , mx[a][i]);
                a = fa[a][i];

            }

        }

        mxx = maxll(mxx , mx[a][0]);
        a = fa[a][0];

    }

    for(int i=H-1; i>=0; i--){

        if(!isfa(fa[b][i] , a)){

            mxx = maxll(mxx , mx[b][i]);
            b = fa[b][i];

        }

    }

    mxx = maxll(mxx , mx[b][0]);

    return mxx;

}

int main(){

    IO

    int n , m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){

        dsu[i] = i;

        for(int j=0; j<H; j++) mx[i][j] = 0;

    }

    for(int i=0; i<m; i++){

        int a , b;
        ll c;
        cin >> a >> b >> c;

        if(a == b) continue;

        G[a].pb(mp(b , c));
        G[b].pb(mp(a , c));

        edge.pb((E){a , b , c});

    }

    sort(edge.begin() , edge.end());

    ll len = 0;
    int cnt = 0;

    for(int i=0; i<m; i++){

        int V = edge[i].v , U = edge[i].u;
        int P = query(V) , Q = query(U);

        if(P != Q){

            dsu[P] = Q;

            ll W = edge[i].w;

            MST[V].pb(mp(U , W));
            MST[U].pb(mp(V , W));

            len += W;
            cnt++;

        }

    }

    if(cnt != n - 1) cout << "-1 -1\n";
    else{

        ll mi = LONG_MAX;

        dfs(1 , 1);

        for(int i=0; i<m; i++){

            int V = edge[i].v , U = edge[i].u;

            if(fa[V][0] != U && fa[U][0] != V){

                ll ans = lca(V , U) , W = edge[i].w;

                if(len - ans + W != len) mi = minll(mi , len - ans + W);

            }

        }

        if(mi == LONG_MAX) cout << len << " -1\n";
        else cout << len << " " << mi << '\n';

    }

    return 0;

}