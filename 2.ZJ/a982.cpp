#include <iostream>
#include <queue>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef pair<int , int> pii;

int maze[105][105] , dir[4][2] = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};

void print(int n){

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++) cout << maze[i][j];
        cout << '\n';

    }

}

int main(){

    IO
    
    int n;
    cin >> n;

    queue<pii> q;

    for(int i=0; i<n; i++){

        for(int j=0; j<n ;j++){

            char temp;
            cin >> temp;

            if(temp == '#') maze[i][j] = 0;
            else maze[i][j] = 1;

        }

    }

    //print(n);

    q.push(mp(1 , 1));
    q.push(mp(-1 , -1));

    int cnt = 1;

    while(!q.empty()){

        pii cur = q.front();
        q.pop();

        if(cur.ff == -1 && q.size() != 0){

            cnt++; 
            q.push(mp(-1 , -1));
            continue;

        }

        int nx , ny;

        for(int i=0; i<4; i++){

            nx = cur.ff + dir[i][0];
            ny = cur.ss + dir[i][1];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n && maze[nx][ny] == 1){

                maze[nx][ny] = 0;
                q.push(mp(nx , ny));

                if(nx == n - 2 && ny == n - 2) break;

            } 

        }
        
        if(nx == n - 2 && ny == n - 2) break;

    }

    if(q.empty() && maze[n - 2][n - 2] == 1) cout << "No solution!\n";
    else cout << cnt + 1 << '\n'; 

    return 0;

}