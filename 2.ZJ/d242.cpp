#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back
#define pp pop_back

using namespace std;

const int N = 5e5 + 5;

vector<int> v , ans;
int dp[N] , seq[N];

int main(){

    IO

    int n , ind = 0 , mx = 0;

    cin >> n;
    seq[0] = n;
    v.pb(n);
    dp[ind] = 1;
    ind++;

    while(cin >> n){

        seq[ind] = n;

        if(n > v.back()){

            v.pb(n);
            dp[ind] = v.size();

        }else{

            vector<int>::iterator it = lower_bound(v.begin() , v.end() , n);
            *it = n;

            dp[ind] = (int)(it - v.begin()) + 1;

        }

        mx = max(mx , dp[ind]);

        ind++;

    }

    int* ans = new int[mx];
    int temp = mx;

    cout << mx << "\n-\n";

    for(int i=ind-1; i>=0; i--){

        if(dp[i] == mx) ans[mx - 1] = seq[i] , mx--;
        if(mx == 0) break;

    }

    for(int i=0; i<temp; i++) cout << ans[i] << '\n';

    delete []ans;

    return 0;

}