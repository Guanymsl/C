#include <iostream>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define int long long

using namespace std;

int gcd(int m , int n){

    return (m % n == 0) ? n : gcd(n , m % n);

}

signed main(){

    IO

    int a , b;

    while(cin >> a >> b){

        cout << "[" << a / b;

        a = a % b;

        if(a != 0) cout << ";";

        while(a > 1){

            int p = gcd(a , b);

            a = a / p;
            b = b / p;

            swap(a,b);

            cout << a / b;

            a = a % b;

            if(a != 0) cout << ",";

        }

        if(a != 0) cout << b;

        cout << "]\n";

    }

    return 0;

}