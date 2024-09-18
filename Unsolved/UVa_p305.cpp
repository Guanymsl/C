#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define int long long

using namespace std;

int peo[30];

signed main(){

    IO

    int k;
    
    while(cin >> k && k != 0){

        for(int i=1; i>=1; i++){

            if(i % (2 * k) >= 1 && i % (2 * k) <= k) continue;
            else{

                for(int j=0; j<k; j++) peo[j] = 2;
                for(int j=k; j<2*k; j++) peo[j] = 1;

                int bad = k , ind = 0 , cnt = 0;

                while(bad != 0){

                    if(peo[ind] != 0) cnt++;

                    if(cnt == i && peo[ind] == 2) break;
                    else if(cnt == i && peo[ind] == 1) peo[ind] = 0 , bad-- , cnt = 0;
                    
                    ind++;

                    if(ind == 2*k) ind = 0;

                }

                if(bad == 0){

                    cout << i << '\n';
                    break;

                }

            }

        }
    
    }

    return 0;

}