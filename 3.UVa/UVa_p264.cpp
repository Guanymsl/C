#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n;
     
    while(cin >> n && n != cin.eof()){

        cout << "TERM " << n << " IS ";

        int t = floor((sqrt((double)(n - 1) * 8 + 1) - 1) / 2);

        int p = n - (t + 1) * t / 2 , q = t + 2 - p;

        if(t % 2 == 0) swap(p , q);

        cout << p << "/" << q <<'\n'; 
        
    }

    return 0;

}