#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long

using namespace std;

int main(){

    IO

    ll m , n;

    while(cin >> m >> n && m + n != 0){

        ll mi = min(m , n);

        ll ans = (m + 1) * (n + 1) * mi - (m + n + 2) * mi * (mi + 1) / 2 + mi * (mi + 1) * (2 * mi + 1) / 6;

        cout << ans << '\n';

    }

    return 0;

}