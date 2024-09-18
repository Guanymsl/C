#include <iostream>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    double a , b , c , d , e , f;
    cin >> a >> b >> c >> d >> e >>f;

    double w = a * e - b * d , x = c * e - b * f , y = a * f - c * d;

    if(w == 0 && x == 0 && y == 0) cout << "Too many\n";
    else if(w == 0) cout << "No answer\n";
    else cout << fixed << setprecision(2) << "x=" << x / w << '\n' << "y=" << y / w << '\n';

    return 0;

}