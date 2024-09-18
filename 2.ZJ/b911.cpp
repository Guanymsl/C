#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n;

    while(cin >> n){

        if(n == 0) cout << 0;
        else cout << (int)log2(n) + 1 << '\n';

    }

    return 0;

}