#include <iostream>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;

    while(cin >> s && s != "0:00"){

        int l = s.length();
        int m = (int)(s[l-1] - '0') * 10 + (int)(s[l-2] - '0') * 100 , h = (int)(s[l-4] - '0') * 10;

        if(l == 5) h += (int)(s[0] - '0') * 100;
        
        int ma = 6 * m , ha = 30 * h + m / 2;

        double ans = min(3600 - abs(ma - ha) , abs(ma - ha));

        cout << fixed << setprecision(3) << ans / 10 << '\n';

    }

    return 0;
}