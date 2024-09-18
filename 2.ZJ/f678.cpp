#include <iostream>
#include <queue>
#include <vector>
#include <climits>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef pair<int , int> pii;

struct E{

    int num;
    int w;

};

bool operator<(E e1 , E e2){

    return e1.w > e2.w;

}

const int N = 1e6 + 5 , M = INT_MAX;

priority_queue<E> pq;
vector<pii> G[N];

int dis[N] , vis[N];

int main(){

    int n , m , ans = 0;
    cin >> n >> m;

    for(int i=0; i<n; i++) dis[i] = M , vis[i] = 0;

    for(int i=0; i<m; i++){

        int u , v , w;
        cin >> u >> v >> w;

        G[u].pb(mp(v , w));
        G[v].pb(mp(u , w));

    }

    pq.push((E){0 , 0});
    dis[0] = 0;

    while(!pq.empty()){

        E cur = pq.top();
        pq.pop();

        if(vis[cur.num]) continue;
        vis[cur.num] = 1;

        ans += cur.w;

        for(int i=0; i<(int)G[cur.num].size(); i++){

            int next_node = G[cur.num][i].ff;

            if(vis[next_node] == 0 && dis[next_node] > G[cur.num][i].ss){

                dis[next_node] = G[cur.num][i].ss;
                pq.push((E){next_node , dis[next_node]});

            }

        }

    }

    cout << ans << '\n';

    return 0;

}