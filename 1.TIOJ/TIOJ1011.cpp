#include <iostream>
#include <algorithm>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long

using namespace std;

int main(){

    IO

    ll a , b;
    cin >> a >> b;
    if(a > b) swap(a , b);

    int cnt = 0;

    while(a != b){

        b = floor(b / 2);
        if(a > b) swap(a , b);
        cnt++;

    }

    cout << cnt << '\n';

    return 0;

}