#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 1e5+5;

int bnd[N][2] , T[N] , C[N] , D[N];

int main(){

    IO

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> bnd[i][0] >> bnd[i][1];
    }

    int l = bnd[0][0] , r = bnd[0][1] , cnt = 0 , i;
    C[0] = 1;

    for(i=1; i<n; i++){

        if(bnd[i][1]<l || bnd[i][0]>r){

            D[cnt] = i;
            T[cnt] = min(l,r);
            cnt++;
            C[cnt] = i+1;

            l = bnd[i][0];
            r = bnd[i][1];

        }
        else{

            l = max(l,bnd[i][0]);
            r = min(r,bnd[i][1]);

        }
    }

    D[cnt] = i;
    T[cnt] = min(l,r);
    cnt++;

    cout << cnt << '\n';
    for(int i=0; i<cnt; i++) cout << T[i] << " " << C[i] << " " << D[i] << '\n';
}