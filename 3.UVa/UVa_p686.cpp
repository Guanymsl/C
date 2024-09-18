#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 32768;

int prime[N + 5];

int main(){

    IO

    prime[0] = prime[1] = prime[4] = 0;
    prime[2] = prime[3] = prime[5] = 1;

    for(int i=1; i<N/6; i++){

        prime[6 * i] = prime[6 * i + 2] = prime[6 * i + 3] = prime[6 * i + 4] = 0;
        prime[6 * i - 1] = prime[6 * i + 1] = 1;

        for(int j=2; j<6*i-1; j++){

            if(prime[j] == 1){

                if((6 * i - 1) % j == 0 ){

                    prime[6 * i - 1]--;
                    break;

                }

            }

        }

        for(int j=2; j<6*i+1; j++){

            if(prime[j] == 1){

                if((6 * i + 1) % j == 0 ){

                    prime[6 * i + 1]--;
                    break;

                }

            }

        }

    }

    //for(int i=1; i<=100; i++) cout << "prime[" << i << "] = " << prime[i] << '\n';

    int n;

    while(cin >> n && n != 0){

        int cnt = 0;

        for(int i=2; i<=n/2; i++) if(prime[i] == 1 && prime[n-i] == 1) cnt++;

        cout << cnt << '\n';

    }

    return 0;

}