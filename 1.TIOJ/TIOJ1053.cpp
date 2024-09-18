#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int p , q;
    cin >> p >> q;

    if(max(p , q) % min (p , q) == 0) cout << "Y\n";
    else cout << "N\n";

    return 0;

}