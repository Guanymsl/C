#include <iostream>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define int long long

using namespace std;

int item[105] , weight[10005];

signed main(){

    IO

    int N , P;
    
    while(cin >> N >> P && N){

        for(int i=0; i<N; i++) cin >> item[i];

        sort(item , item + N);

        for(int j=0; j<=P; j++) weight[j] = 0;

        for(int j=0; j<=P; j+=item[0]) weight[j] = 1;

        for(int i=1; i<N; i++){

            for(int j=item[i]; j<=P; j++){

                weight[j] += weight[j-item[i]];

            }
        }

        cout << weight[P] << '\n';

    }

    return 0;

}