#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 1e2 + 5;

int dp[N][N][N];

int max3(int x , int y , int z){

    return max(x , max(y , z));

}

int compare(char x , char y , char z){

    if(x == y && y == z) return 3;
    if(x != y && y != z && z != x) return 1;
    else return 2;

}

int main(){

    IO

    string a , b , c;
    cin >> a >> b >> c;

    memset(dp , 0 , sizeof(dp));

    int la = a.length() , lb = b.length() , lc = c.length();

    for(int i=1; i<=la; i++){

        for(int j=1; j<=lb; j++){

            for(int k=1; k<=lc; k++){

                int comp = compare(a[i - 1] , b[j - 1] , c[k - 1]) , temp;

                if(comp == 3) temp = dp[i - 1][j - 1][k - 1] + 1;
                else if(comp == 1) temp = max3(dp[i][j - 1][k - 1] , dp[i - 1][j][k - 1] , dp[i - 1][j - 1][k]);
                else{

                    if(a[i - 1] == b[j - 1]) temp = max(dp[i - 1][j - 1][k] , dp[i][j][k - 1]);
                    else if(b[j - 1] == c[k - 1]) temp = max(dp[i][j - 1][k - 1] , dp[i - 1][j][k]);
                    else temp = max(dp[i - 1][j][k - 1] , dp[i][j - 1][k]);

                }

                dp[i][j][k] = temp;

            }

        }

    }

    cout << dp[la][lb][lc] << '\n';

    return 0;

}