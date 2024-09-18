#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long

using namespace std;

int main(){

    IO

    int n;
    cin >> n;

    ll *num = new ll[n];

    for(int i=0; i<n; i++) cin >> num[i];

    ll ans = 0;

    for(int i=1; i<n; i++) if(num[i] < num[i - 1]) ans += num[i - 1] - num[i] , num[i] = num[i - 1];

    cout << ans << '\n';

    delete []num;

    return 0;

}