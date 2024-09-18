#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 1e3 + 5;

int dp[N][N];

int main(){

    IO

    string a , b;

    while(cin >> a >> b){

        memset(dp , 0 , sizeof(dp));

        int la = a.length() , lb = b.length();

        for(int i=0; i<la; i++){

            for(int j=0; j<lb; j++){

                if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);

            }

        }

        cout << dp[la - 1][lb - 1] << '\n';

    }

    return 0;

}