#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int dp[55];

int main(){

    IO

    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=50; i++) dp[i] = dp[i-1] + dp[i-2];

    int num;

    while(cin >> num && num != 0) cout << dp[num] << '\n';

    return 0;

}