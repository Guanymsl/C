#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long

using namespace std;

int main(){

    IO

    double s , r;

    cin >> s >> r;

    ll ans = static_cast<int>(s*(pow((1+r/100),13)-1)/r/0.01);
    cout << ans << '\n';

    return 0;

}