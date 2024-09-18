#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long

using namespace std;

int main(){

    IO

    ll a , b;

    while(cin >> a >> b && !cin.eof()) cout << abs(a-b) << '\n';

    return 0;
    
}