#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

typedef long long ll;

const ll N = 1e4 + 5 , mod = 1e9 + 7;

ll dp[N];

int main(){

    IO

    int n;

    for(int i=0; i<N; i++) dp[i] = 0;

    dp[0] = dp[1] = 1;
    dp[2] = 2;

    int mx = 3;

    while(cin >> n){

        if(dp[n] != 0) cout << dp[n] << '\n';
        else{

            for(int i=mx; i<=n; i++) dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;

            mx = max(mx , n);

            cout << dp[n] << '\n';

        }

    }

    return 0;

}