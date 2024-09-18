#include <iostream>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    int n;
    cin >> n;

    int *num = new int[n];

    for(int i=0; i<n; i++) cin >> num[i];

    sort(num , num + n);

    int ans = num[0] , mx = 0 , cnt = 1;

    for(int i=1; i<n; i++){

        if(num[i] == num[i - 1]) cnt++;
        else{

            mx = max(mx , cnt);
            if(mx == cnt) ans = num[i - 1];
            cnt = 1;

        }

    }

    mx = max(mx , cnt);
    if(mx == cnt) ans = num[n - 1];

    cout << ans << " " << mx << '\n';

    delete []num;

    return 0;

}