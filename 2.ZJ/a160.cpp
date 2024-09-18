#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

int bd[15][15] , cnt , n , col[15] , diag[30] , anti[30];

void print(){

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            if(bd[i][j] == 1) cout << "Q";
            else cout << "x";

        }

        cout << '\n';

    }

    cout << '\n';

}

void dfs(int x){

    if(x == n){

        cnt++;
        print();
        return;

    }

    for(int j=0; j<n; j++){

        if(bd[x][j] == 0){

            if(col[j] == 0 && diag[x + j] == 0 && anti[x - j + n - 1] == 0){

                col[j] = 1;
                diag[x + j] = 1;
                anti[x - j + n - 1] = 1;

                bd[x][j] = 1;

                dfs(x + 1);

                col[j] = 0;
                diag[x + j] = 0;
                anti[x - j + n - 1] = 0;

                bd[x][j] = 0;

            }

        }
        
    }

}

int main(){

    IO

    while(cin >> n && n){

        cnt = 0;

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++) bd[i][j] = 0;

        }

        for(int i=0; i<2*n-1; i++) diag[i] = anti[i] = 0;
        for(int i=0; i<n; i++) col[i] = 0;

        dfs(0);

        cout << cnt << '\n' << '\n';

    }

    return 0;

}