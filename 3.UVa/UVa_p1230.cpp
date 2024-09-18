#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long
#define ul unsigned long
#define pb push_back

using namespace std;

vector<int> v;

ll mod(ll x , ll y , ll n){

    if(y == 1) return x % n;

    if(y % 2 == 1){

        y--;
        v.pb(x);

    }

    return mod((x * x) % n , y / 2 , n);

}

int main(){

    IO

    int t;
    cin >> t;

    while(t--){

        ll x , y , n;
        cin >> x >> y >> n;

        ll ans = mod(x , y , n);

        for(ul i=0; i<v.size(); i++) ans = (ans * v[i]) % n;

        cout << ans << '\n';

        v.clear();

    }

    return 0;

}