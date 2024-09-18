#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

#define ll long long

using namespace std;

int main(){

    IO

    /*int cnt = 0;

    for(ll i=1; ; i++){

        ll j = i;

        while(j%2==0) j = j/2;
        while(j%3==0) j = j/3;
        while(j%5==0) j = j/5;

        if(j==1) cnt++ , cout << cnt << ": " << i << '\n' ;

        if(cnt==1500) break;

    }*/

    cout << "The 1500'th ugly number is 859963392." <<'\n';

    return 0;
    
}