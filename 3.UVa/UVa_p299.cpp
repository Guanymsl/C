#include <iostream>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int L[55];

int main(){

    IO

    int t;
    cin >> t;

    while(t--){

        int l;
        cin >> l;

        for(int i=0; i<55; i++) L[i] = 0;

        for(int i=0; i<l; i++) cin >> L[i];

        int cnt = 0;

        for(int i=0; i<l; i++){

            for(int j=0; j<l-1; j++) if(L[j] > L[j+1]) swap(L[j] , L[j+1]) , cnt++;

        }

        cout << "Optimal train swapping takes " << cnt << " swaps.\n";

    }

    return 0;

}