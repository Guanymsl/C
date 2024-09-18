#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long
#define ul unsigned long
#define pb push_back

using namespace std;

vector<ll> v;

int main(){

    IO

    ll z , i , m , l;
    int ind = 1;

    while(cin >> z >> i >> m >> l && z + i + m + l != 0){

        int st = 1;

        cout << "Case " << ind << ": ";

        v.pb(l);

        while(st){

            ll num = (z * l + i) % m;
            //cout << num << '\n';

            for(ul k=0; k<v.size(); k++){

                if(v[k] == num){
                    
                    cout << v.size() - k << '\n';
                    st = 0;

                }

            }

            v.pb(num);
            l = num;

        }

        v.clear();
        ind++;

    }

    return 0;

}