#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define int long long

using namespace std;

signed main(){

    IO

    int n;
    cin >> n;

    while(n--){

        int x , y;
        cin >> x >> y;

        int m = max(x , y) , ans = 0;

        if(m & 1){

            if(y == m) ans = m * m - x + 1;
            else ans = (m - 1) * (m - 1) + y;

        }else{

            if(y == m) ans = (m - 1) * (m - 1) + x;
            else ans = m * m - y + 1;

        }

        cout << ans << '\n';

    }

    return 0;

}