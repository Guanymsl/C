#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

const int N = 1e4 + 5;

struct E{

    int u;
    int v;
    int w;

};

int dsu[N];
vector<E> edge;

bool cmp(E e1 , E e2){

    return e1.w < e2.w;

}

int query(int x){

    if(dsu[x] == x) return x;

    dsu[x] = query(dsu[x]);
    return dsu[x];

}

void join(int p , int q){

    dsu[max(p , q)] = min(p , q);

}

int main(){

    IO

    int n , m;

    while(cin >> n >> m && n){

        int ans = 0 , cnt = 0;

        memset(dsu , 0 , N);

        for(int i=1; i<=n; i++) dsu[i] = i;

        for(int i=0; i<m; i++){

            int u , v , c;
            cin >> u >> v >> c;

            edge.pb((E){u , v , c});

        }

        sort(edge.begin() , edge.end() , cmp);

        for(int i=0; i<m; i++){

            int P = query(edge[i].u) , Q = query(edge[i].v);

            if(P == Q) continue;

            join(P , Q);
            ans += edge[i].w;
            cnt++;

        }

        cout << ((cnt == n - 1) ? ans : -1) << '\n';

        edge.clear();

    }

    return 0;

}