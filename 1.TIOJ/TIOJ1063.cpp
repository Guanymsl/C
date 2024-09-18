#include <iostream>
#include <climits>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 205;

int gnd[N][N] , h[N][N] , w[N][N];

int main(){
    
    IO

    int m , n;
    cin >> m >> n;

    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++) cin >> gnd[i][j];
        
    }

    for(int i=0; i<m; i++){

        int cnt = 1;

        for(int j=0; j<n; j++){

            if(gnd[i][j]){

                w[i][j] = cnt;
                cnt++;

            }else{

                w[i][j] = 0;
                cnt = 1;

            }

        }

    }

    for(int j=0; j<n; j++){

        int cnt = 1;

        for(int i=0; i<m; i++){ 

            if(gnd[i][j]){

                h[i][j] = cnt;
                cnt++;

            }else{

                h[i][j] = 0;
                cnt = 1;

            }

        }

    }

    int ans = 0;

    for(int i=m-1; i>=0; i--){

        for(int j=n-1; j>=0; j--){

            int rec = INT_MAX;

            for(int k=0; k<w[i][j]; k++){

                rec = min(rec , h[i][j-k]);

            }

            ans = max(ans , w[i][j]*rec);

        }
    }

    cout << ans << '\n';

}