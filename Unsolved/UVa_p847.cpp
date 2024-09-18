#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    unsigned int n;



    while(cin >> n && !cin.eof()){

        int cnt = 0;

        while(true){

            n = (n - 1) / 9;

            cnt++;

            if(n == 0) break;

            n = n / 2;

            cnt++;

            if(n == 0) break;

        }

        if(cnt & 1) cout << "Stan wins.\n";
        else cout << "Ollie wins.\n";

    }

    return 0;

}