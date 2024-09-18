#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

typedef long long ll;

int main(){

    IO

    vector<ll> v;

    string s;
    cin >> s;

    int l = s.length();
    ll cnt = 0;
    bool isQ = false;
    
    for(int i=0; i<l; i++){

        if(s[i] == 'Q' && isQ) v.pb(cnt) , cnt = 0;

        if(s[i] == 'Q' && !isQ) isQ = true;

        if(s[i] == 'A' && isQ) cnt++;

    }

    ll sum = 0 , vs = v.size();

    for(ll i=0; i<vs; i++) sum += v[i] * (i + 1) * (vs - i);

    cout << sum << '\n';

    return 0;

}