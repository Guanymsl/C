#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;

    while(cin >> s && s != "0"){

        int l = s.length() , ans = 0;

        for(int i=l-1; i>=0; i--){

            int p = pow(2 , l-i) - 1;
            ans += (int)(s[i] - '0') * p;

        }

        cout << ans << '\n';

    }

    return 0;

}