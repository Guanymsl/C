#include <iostream>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int x , y;
    cin >> x >> y;

    x = (x + 2 + (y + 30) / 60) % 24;
    y = (y + 30) % 60;
    
    cout << setw(2) << setfill('0') << x;
    cout << ":";
    cout << setw(2) << setfill('0') << y << '\n';

    return 0;

}