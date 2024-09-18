#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

const int N = 1e4 + 5 , MX = 1e8 + 5;

typedef pair<int , double> pid;

struct Node{

    int num;
    double c;

};

bool operator<(Node n1 , Node n2){

    return n1.c > n2.c;

}

priority_queue<Node> pq;
vector<pid> G[N];

int vis[N];
double ans[N];

int main(){

    IO

    int n , m , s , t;
    cin >> n >> m >> s >> t;

    for(int i=1; i<=n; i++) vis[i] = 0 , ans[i] = MX;

    while(m--){

        int A , B;
        double C;

        cin >> A >> B >> C;

        G[A].pb(mp(B , log10(1 + C)));

    }

    /*for(int i=1; i<=n; i++){

        for(int j=0; j<(int)G[i].size(); j++) cout << G[i][j].ss << " ";
        cout << '\n';

    }*/

    ans[s] = 0.0;
    pq.push((Node){s , 0.0});

    while(!pq.empty()){

        Node cur = pq.top();
        pq.pop();

        if(vis[cur.num] == 1) continue;
        vis[cur.num] = 1;

        for(int i=0; i<(int)G[cur.num].size();i++){

            int next_node = G[cur.num][i].ff;

            if(ans[next_node] > ans[cur.num] + G[cur.num][i].ss){

                ans[next_node] = ans[cur.num] + G[cur.num][i].ss;
                pq.push((Node){next_node , ans[next_node]});

            }

        }

    }

    //cout << pow(10 , ans[t]) << '\n';

    int itg = floor(ans[t]);

    cout << fixed << setprecision(2) << pow(10.0 , ans[t] - itg);
    cout << "e+";
    cout << setw(3) << setfill('0') << (int)itg << '\n';

    return 0;

}