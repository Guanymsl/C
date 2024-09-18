#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define int long long

using namespace std;

signed main(){

    IO

    int a , b;
    
    while(cin >> a >> b && a){

        int p = sqrt(a) , cnt = 0 , ans = floor(sqrt(b)) - floor(sqrt(a));

        if(p * p == a) cnt = 1;

        //cout << ans << " " << cnt << '\n';

        cout << ans + cnt << '\n';

    }

    return 0;

}