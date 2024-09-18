#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n;

    while(cin >> n && n){

        int cnt = 0;

        while(n % 2) cnt++ , n /= 2;

        cout << cnt << '\n';
        
    }

    return 0;

}