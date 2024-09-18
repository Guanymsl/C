#include <iostream>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n;
    cin >> n;

    int *num = new int[n - 1];

    for(int i=0; i<n-1; i++) cin >> num[i];

    sort(num , num + n - 1);

    for(int i=0; i<n-1; i++){

        if(i + 1 != num[i]){

            cout << i + 1 << '\n';
            break;

        }

        if(i == n - 2) cout << n << '\n'; 

    }

    delete []num;

    return 0;

}