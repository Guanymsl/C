#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define int long long

using namespace std;

signed main(){

    int n;

    while(cin>>n){

        int k = pow(10,n/2);

        for(int i=0; i<k; i++){

            if(pow((i*i/k+i*i%k),2)==i*i){
                
                int num = 1;

                for(int j=1; j<n; j++){

                    int p = pow(10,j);
                    if(i*i/p>0) num++;

                }

                for(int j=1; j<=n-num; j++) cout << 0;

                cout << i*i << '\n';

            }

        }

    }

    return 0;

}