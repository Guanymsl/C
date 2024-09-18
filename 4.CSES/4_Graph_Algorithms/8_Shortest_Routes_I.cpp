#include <iostream>
#include <vector>
#include <queue>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef pair<int , int> pii;
typedef long long ll;

const int N = 1e5 + 5;
const ll MX = 1e14 + 5;

struct Node{

    int num;
    ll dis;

};

bool operator<(Node n1 , Node n2){

    return n1.dis > n2.dis;

}

priority_queue<Node> pq;
vector<pii> G[N];

int vis[N];
ll ans[N];

int main(){

    IO

    int n , m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) vis[i] = 0 , ans[i] = MX;

    while(m--){

        int a , b , c;
        cin >> a >> b >> c;

        G[a].pb(mp(b , c));

    }

    ans[1] = 0;
    Node st = {1 , 0};
    pq.push(st);

    while(!pq.empty()){

        Node cur = pq.top();
        pq.pop();

        if(vis[cur.num] == 1) continue;
        vis[cur.num] = 1;

        for(int i=0; i<(int)G[cur.num].size(); i++){

            int next_node = G[cur.num][i].ff;

            if(ans[next_node] > ans[cur.num] + G[cur.num][i].ss){

                ans[next_node] = ans[cur.num] + G[cur.num][i].ss;
                pq.push((Node){next_node , ans[next_node]});

            }

        }

    }

    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << '\n';

    return 0;

}