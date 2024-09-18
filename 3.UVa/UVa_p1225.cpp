#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int ans[10];

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        for(int i=0; i<=9; i++) ans[i] = 0;

        for(int i=0; i<=3; i++){

            int div = pow(10,i) , lim = (n % (10 * div)) / div;

            //cout << lim << " ";

            for(int j=0; j<=9; j++){

                if(j < lim && j != 0) ans[j] += (n / (div * 10) + 1) * div ;
                else if(j > lim || j == 0) ans[j] += n / (div * 10) * div;
                else ans[j] += ((n / (div * 10) * div + 1) + n % div);

            }

        }

        for(int i=0; i<=9; i++){

            cout<< ans[i];
            if(i != 9) cout << " "; 

        }

        cout << '\n';

    }

    return 0;

}