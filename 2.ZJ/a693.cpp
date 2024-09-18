#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n , m;
    
    while(cin >> n >> m){

        int* food = new int[n + 1];

        food[0] = 0;

        cin >> food[1];

        for(int i=2; i<=n; i++){

            cin >> food[i];
            food[i] += food[i - 1];

        }

        while(m--){

            int l , r;
            cin >> l >> r;

            cout << food[r] - food[l - 1] << '\n';

        }

        delete []food;

    }

    return 0;

}