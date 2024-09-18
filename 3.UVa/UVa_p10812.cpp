#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n;
    cin >> n;

    while(n--){

        int a , b;
        cin >> a >> b;

        if(a < b || (a + b) % 2 == 1) cout << "impossible\n";
        else cout << (a + b) / 2 << " " << (a - b) / 2 << '\n';
        
    }

    return 0;

}