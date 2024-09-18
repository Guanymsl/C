#include <iostream>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define int long long

using namespace std;

signed main(){

    IO

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int hor[n] , ver[n];
        
        int h = 0 , v = 0;

        for(int i=0; i<n; i++){

            cin >> hor[i];
            h += hor[i];

        }

        for(int i=0; i<n; i++){

            cin >> ver[i];
            v += ver[i];

        }

        sort(hor , hor + n);
        sort(ver , ver + n);

        cout << min(h + ver[0] * n , v + hor[0] * n) << '\n';

    }

    return 0;

}