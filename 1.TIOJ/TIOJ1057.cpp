#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

vector<int> v;

int main(){

    IO

    int m , p , n;
    cin >> m >> p >> n;

    for(int i=0; i<n; i++){

        int temp;
        cin >> temp;
        v.pb(temp);

    }

    int pos = 0 , cnt = 0 , ind = -1;
    bool ans = true;

    if(v[0] > m) ans = false;
    else{

        while(pos < p){

            //cout << "pos = " << pos << '\n';

            pos += m;

            if(pos >= p){

                cnt++;
                break;

            }

            int i;

            for(i = ind + 1; i<n; i++){

                if(v[i] <= pos && (i == n - 1 || v[i + 1] >= pos)){

                    ind = i;
                    break;

                }

            }

            if(i == n){

                ans = false;
                break;

            }

            pos = v[ind];
            cnt++;

        }

    }

    if(ans) cout << cnt - 1 << '\n';
    else cout << "IMPOSSIBLE\n";

    return 0;

}