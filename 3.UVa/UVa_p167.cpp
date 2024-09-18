#include <iostream>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int gnd[8][8];

int hor[8] , posd[17] , negd[17];

int cnt , ans , M;

void search(int ind){

    if(ind==8){

        M = max(M , ans);
        return;

    }

    for(int i=0; i<8; i++){

        if(hor[i]!=0 || posd[ind+i]!=0 || negd[ind-i+8]!=0) continue;
        else{

            hor[i] = 1;
            posd[ind+i] = 1;
            negd[ind-i+8] = 1;

            ans += gnd[i][ind];

            search(++ind);

            ind--;

            hor[i] = 0;
            posd[ind+i] = 0;
            negd[ind-i+8] = 0;
            
            ans -= gnd[i][ind];

        }

    }

    return;
    
}

int main(){
    
    IO

    int k;
    cin >> k;

    while(k--){

        for(int i=0; i<8; i++) hor[i] = 0;
        for(int i=0; i<17; i++) posd[i] = 0 , negd[i] = 0;

        for(int i=0; i<8; i++){

            for(int j=0; j<8; j++) cin >> gnd[i][j];

        }

        M = 0;
        ans = 0;

        search(0);

        cout << setw(5) << M << '\n';

    }

    return 0;

}