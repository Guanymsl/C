#include <iostream>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int dir[4][2] = {{0 , 1} , {1 , 0} , {0 , -1} , {0 , 1}};

int main(){

    IO

    int t;
    cin >> t;

    while(t--){

        int n , m;
        cin >> n >> m;

        int** mtx = new int*[n];
        for(int i=0; i<n; i++) mtx[i] = new int[n];

        int x = 0 , y = 0 , cnt = 1 , turn = n - 1 , ind = 0 , rev = turn - 1;

        while(cnt <= n * n){

            if(rev == 0) turn-- , rev = turn - 1 , ind = (ind + 1) % 4;

            mtx[x][y] = cnt;
            cnt++;

            x += dir[ind][0];
            y += dir[ind][1];

            rev--;

            cnt++;

        }

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++) cout << setw(5) << mtx[i][j];
            cout << '\n';

        }

        for(int i=0; i<n; i++) delete [](mtx[i]);
        delete []mtx;

    }

    return 0;

}