#include <iostream>
#include <queue>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef pair<int , int> pii;

int map[1005][1005] , im[1005][1005] , dir[4][2] = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};

int main(){

    IO

    int m , n;
    pii A , B;
    queue<pii> q;
    string s = "DURL";
    vector<char> v;

    cin >> m >> n;

    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++){

            char temp;
            cin >> temp;

            if(temp == 'A') A = mp(i , j);
            if(temp == 'B') B = mp(i , j);

            if(temp == '#') map[i][j] = 0;
            else map[i][j] = 1;

        }

    }

    q.push(A);

    while(!q.empty()){

        pii cur = q.front();
        q.pop();

        int x , y;

        for(int i=0; i<4; i++){

            x = cur.ff + dir[i][0] , y = cur.ss + dir[i][1];

            if(x >= 0 && x < m && y >= 0 && y < n && map[x][y]){

                map[x][y] = 0;
                im[x][y] = i;
                q.push(mp(x , y));

            }

            if(mp(x , y) == B) break;

        }

        if(mp(x , y) == B) break;

    }

    if(q.empty()) cout << "NO\n";
    else{

        while(B != A){

            v.pb(s[im[B.ff][B.ss]]);

            pii rev = mp(B.ff - dir[im[B.ff][B.ss]][0] , B.ss - dir[im[B.ff][B.ss]][1]);

            B = rev;

        }

        cout << "YES\n";
        cout << v.size() << '\n';

        for(vector<char>::reverse_iterator it = v.rbegin(); it!=v.rend(); it++) cout << *it;

        cout << '\n';

    }

    return 0;

}