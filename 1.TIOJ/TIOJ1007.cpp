#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define int long long

using namespace std;

int bulb[20][95];

signed main(){

    int m , n;
    cin >> m >> n;

    bulb[0][0] = bulb[1][0] = 1;

    for(int i=2; i<=m; i++) bulb[i][0] = 0;

    for(int i=1; i<n; i++){

        int cnt = 0;

        for(int j=1; j<=m; j++){

            cnt += bulb[j][i-1];

            bulb[j][i] = bulb[j-1][i-1]; 

        }

        bulb[0][i] = bulb[0][i-1] + cnt;

    }

    int ans = 0;

    for(int i=0; i<=m; i++) ans += bulb[i][n-1];

    cout << ans << '\n';

}