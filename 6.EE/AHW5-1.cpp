#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int det(int a , int b , int c , int d){

    return a * d - b * c;

}

void cof(int n , int mtx[][3] , int adj[][3]){

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            int ind = 0 , val[4] = {0 , 0 , 0 , 1};

            for(int k=0; k<n; k++){

                for(int l=0; l<n; l++) if(k != i && l != j) val[ind] = mtx[k][l] , ind++;

            }

            adj[i][j] = (int)pow(-1 , i + j) * det(val[0] , val[1] , val[2] , val[3]);

        }

    }

    return;

}

int main(){

    IO

    int n , mtx[3][3] , adj[3][3];
    char c;

    cin >> n;

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++) cin >> mtx[i][j];

    }

    cin >> c;

    if(c == 'T'){

        for(int i=0; i<n; i++){
            
            for(int j=0; j<n; j++){

                cout << mtx[j][i];
                if(j != n-1) cout << " ";

            }

            cout << '\n';

        }

    }else{

        int d = 0;

        cof(n , mtx , adj);

        for(int i=0; i<n; i++) d += mtx[i][0] * adj[i][0];

        if(d == 0) cout << "The inverse matrix does not exist!\n";
        else{

            for(int i=0; i<n; i++){

                for(int j=0; j<n; j++){

                    cout << (double)adj[j][i] / (double)d;
                    if(j != n-1) cout << " ";

                }

                cout << '\n';

            }

        }

    }

    return 0;

}