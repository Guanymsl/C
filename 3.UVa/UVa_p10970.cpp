#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int m , n;
    while(cin >> m >> n){

        cout << n*m-1 << '\n';

    }

    return 0;

}