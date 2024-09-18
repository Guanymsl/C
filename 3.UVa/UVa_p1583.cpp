#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int t;
    cin >> t;

    while(t--){

        int n , i;
        cin >> n;

        for(i=n-45; i<n; i++){

            int ans = i;
            
            for(int j=1; j<=6; j++){

                int k = pow(10,j);
                ans+=i%k*10/k;

            }

            if(ans == n){

                cout << i << '\n';
                break;

            }
        }

        if(i == n) cout << 0 << '\n';

    }

    return 0;

}