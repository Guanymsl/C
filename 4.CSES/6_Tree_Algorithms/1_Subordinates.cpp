#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

vector<int> G[N];
int cnt[N];

void dfs(int cur){

    cnt[cur] = 0;

    for(int i=0; i<(int)G[cur].size(); i++) dfs(G[cur][i]);

    for(int i=0; i<(int)G[cur].size(); i++) cnt[cur] += (cnt[G[cur][i]] + 1);

}

int main(){

    IO

    int n;
    cin >> n;

    for(int i=2; i<=n; i++){

        int boss;
        cin >> boss;
        G[boss].pb(i);

    }

    dfs(1);

    for(int i=1; i<=n; i++) cout << cnt[i] << " ";
    cout << '\n';

    return 0;

}