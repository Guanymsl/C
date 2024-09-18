#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int dtb(int m){

    int ans = 0;

    for(int i=13; i>=0; i--){

        int p = pow(2 , i);

        if(m / p == 1) ans++ , m -= p;

    }

    return ans;

}

int htb(int m){

    int ans = 0;

    for(int i=3; i>=0; i--){

        int p = pow(10 , i);

        ans += dtb(m / p);

        m -= m / p * p; 

    }

    return ans;

}

int main(){

    IO

    int n;
    cin >> n;
    
    while(n--){

        int m;
        cin >> m;

        cout << dtb(m) << " " << htb(m) <<'\n';

    }

    return 0;

}