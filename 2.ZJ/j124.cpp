#include <iostream>
#include <stack>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;

stack<pll> st;

int main(){

    ll n;
    cin >> n;

    ll sum = -n;

    st.push(mp(0 , 4));

    if(n & 1) st.push(mp(n , 3));
    else st.push(mp(n , 2));

    while(st.size() > 1){

        cin >> n;

        st.top().ss--;

        if(n == 0){

            while(st.top().ss == 0){

                ll cur = st.top().ff;
                st.pop();
                sum += abs(cur - st.top().ff);

            }

        }else{

            if(n & 1) st.push(mp(n , 3));
            else st.push(mp(n , 2));

        }

    }

    cout << sum << '\n';

    return 0;

}