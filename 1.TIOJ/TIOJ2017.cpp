#include <iostream>
#include <stack>

#define IO ios_base::sync_with_stdio(0), cin.tie(0) , cout.tie(0);
#define ll long long
#define pll pair<ll , ll>
#define mp make_pair
#define f first
#define s second

using namespace std;

const int N = 1e6+5;

ll a[N] , s[N] , d[N];
stack<pll> st; 

int main(){

    IO

    ll n;
    cin >> n;

    for(int i=1; i<=n; i++) cin >> a[i] , s[i] = a[i];
    for(int i=1; i<N; i++) d[i] = 0;
    for(int i=2; i<=n; i++) s[i] += s[i-1];
 
    s[n+1] = -1e11-5;

    st.push(mp(-1,-1));
    st.push(mp(0,0));
    st.push(mp(s[1],1));

    for(int i=2; i<=n+1; i++){

        while(s[i]-st.top().f<0 && st.top().s>=0){

            if(a[st.top().s+1]>=0) d[st.top().s+1] = i-st.top().s-1;
            st.pop();

        }

        st.push(mp(s[i],i));

    }

    ll ans=0;

    //for(int i=1; i<=n; i++) cout << d[i] << " ";
    for(int i=1; i<=n; i++) ans += d[i];

    cout << n*(n+1)/2-ans << '\n';

}