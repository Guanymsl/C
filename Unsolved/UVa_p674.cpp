#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int coin[7500] , num[4] = {5 , 10 , 25 , 50};

int main(){

    IO

    coin[0] = 0;

    int add = 1;

    for(int i=1 ; i<=50; i++){

        for(int j=0; j<4; j++) add += (num[j] - i % num[j]) / num[j];
        
        coin[i] = add;

        cout << coin[i] << " ";

    }

    cout << '\n';

    int query;
    
    while(cin >> query) cout << coin[query] << '\n';

    return 0;

}