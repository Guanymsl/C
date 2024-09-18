#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define int unsigned long long

using namespace std;

signed main(){

    int n,m;

    while(cin >> n >> m && n){

        int mul = max(m , n - m) + 1 , div = min(m , n - m);

        //cout << mul << " " << div << '\n';

        int ans = 1 , ind = 1;

        while(mul <= n || ind <= div){

            while(ans % ind == 0 && ind <= div) ans = ans / ind , ind++;

            if(mul <= n) ans = ans * mul , mul++;

            //cout << ans << '\n';

        }

        cout << n << " things taken " << m << " at a time is " << ans << " exactly.\n";

    }

    return 0;

}
