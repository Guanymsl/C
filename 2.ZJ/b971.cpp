#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int a , b , c;
    cin >> a >> b >> c;

    cout << a << " ";

    while(a != b) a += c , cout << a << " ";
    
    cout << '\n';

    return 0;

}