#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

typedef vector<int> vi;

int mtx[1005][1005] , m , n , ans[1005] , cnt , mi;
vector<vi> v;

void print(){

    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++) cout << mtx[i][j] << " ";
        cout << '\n';

    }

    cout << '\n';

}

void printans(){

    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << '\n';

}

void dfs(int x){

    //printans();

    if(x == n){

        mi = min(mi , cnt);
        return;

    }

    if(ans[x] == 1) dfs(x + 1);
    else{

        for(int i=0; i<m; i++){

            if(mtx[i][x] == 1){

                bool tr = true;

                for(int j=0; j<(int)v[i].size(); j++){

                    if(ans[v[i][j]] == 1){

                        tr = false;
                        break;

                    }

                }

                if(tr){

                    for(int j=0; j<(int)v[i].size(); j++) ans[v[i][j]] = 1;
                    cnt++;

                    dfs(x + 1);

                    for(int j=0; j<(int)v[i].size(); j++) ans[v[i][j]] = 0;
                    cnt--;

                }

            }

        }

    }

}

int main(){

    IO

    while(cin >> m >> n && m){

        cnt = 0 , mi = 1005;

        for(int i=0; i<m; i++){

            vi tem;

            int c;
            cin >> c;

            for(int j=0; j<n; j++) mtx[i][j] = 0;

            int temp;

            for(int j=0; j<c; j++){

                cin >> temp;
                tem.pb(temp - 1);
                mtx[i][temp - 1] = 1;

            }

            v.pb(tem);

        }

        for(int i=0; i<n; i++) ans[i] = 0;

        //print();

        dfs(0);

        if(mi == 1005) cout << "No\n";
        else cout << mi << '\n';

        v.clear();

    }

    return 0;

}