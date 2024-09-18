#include <iostream>
#include <iomanip>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

int bin[32];

using namespace std;

void dtb(int n){

    for(int i=0; i<32; i++){

        int p = pow(2 , 31 - i);
        bin[i] = n / p;
        n = n % p;

    }

    return;

}

int main(){

    IO

    int n;
    cin >> n;

    dtb(n);

    double sign = pow(-1 , bin[0]) , E = 0 , frac = 1;

    for(int i=0; i<8; i++){

        int p = pow(2 , 7-i);
        E += bin[i+1] * p;

    }

    for(int i=0; i<23; i++){

        double p = pow(2 , -1 - i);
        frac += bin[i+9] * p;

    }

    double ans = sign * pow(2 , E - 127) * frac;

    cout << fixed << setprecision(5) << ans << '\n';

    return 0;

}