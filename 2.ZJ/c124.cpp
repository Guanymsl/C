#include <iostream>
#include <queue>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

struct blk{

    int x;
    int y;
    int z;

};

int maze[35][35][35] , dir[6][3] = {{1 , 0 , 0} , {-1 , 0 , 0} , {0 , 1 , 0} , {0 , -1 , 0} , {0 , 0 , 1} , {0 , 0 , -1}};

int main(){

    IO

    int l , r , c;

    while(cin >> l >> r >> c && l){

        queue<blk> q;
        blk S , E;

        for(int i=0; i<l; i++){

            for(int j=0; j<r; j++){

                for(int k=0; k<c; k++){

                    char temp;
                    cin >> temp;

                    if(temp == 'S') S = (blk){i , j , k};
                    if(temp == 'E') E = (blk){i , j , k};

                    if(temp == '#') maze[i][j][k] = 0;
                    else maze[i][j][k] = 1;

                }

            }

        }

        q.push(S);
        q.push((blk){-1 , -1 , -1});

        int cnt = 0;

        while(!q.empty()){

            //cout << "q.size() = " << q.size() << '\n';

            blk cur = q.front();
            q.pop();

            if(cur.x == -1 && q.size() != 0){

                cnt++;
                q.push((blk){-1 , -1 , -1});
                continue;

            }

            int nx , ny , nz;

            for(int i=0; i<6; i++){

                nx = cur.x + dir[i][0];
                ny = cur.y + dir[i][1];
                nz = cur.z + dir[i][2];

                if(nx >= 0 && nx < l && ny >= 0 && ny < r && nz >= 0 && nz < c && maze[nx][ny][nz] == 1){
                    
                    maze[nx][ny][nz] = 0;
                    q.push((blk){nx , ny , nz});

                    if(nx == E.x && ny == E.y && nz == E.z) break;

                }

            }

            if(nx == E.x && ny == E.y && nz == E.z) break;

        }

        if(q.empty()) cout << "Trapped!\n";
        else cout << "Escaped in " << cnt + 1 << " minute(s).\n";

    }

    return 0;

}