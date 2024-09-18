#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long

using namespace std;

int main(){

    IO

    ll n;
    cin >> n;

    cout << n << " ";

    while(n != 1){

        if(n & 1) n = 3 * n + 1;
        else n /= 2;

        cout << n << " ";

    }

    cout << '\n';

    return 0;

}