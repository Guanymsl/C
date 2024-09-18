#include <iostream>
#include <iomanip>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int num[55];

int gcd(int m , int n){

    return (m % n == 0) ? n : gcd(n , m % n);

}

int main(){

    IO

    double n;

    while(cin >> n && n != 0){

        for(int i=0; i<n; i++) cin >> num[i];

        double cnt = 0;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++) if(gcd(num[i] , num[j]) == 1) cnt++;
        }

        if(cnt == 0) cout << "No estimate for this data set.\n";
        else{

            double ans = sqrt(3 * n * (n - 1) / cnt);

            cout << fixed << setprecision(6) << ans << '\n';

        }

    }

    return 0;

}