#include <iostream>
#include <map>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 1e4 + 5 , M = 1e5 + 5;

int m[N] , h[N] , dp[2][M] , mx[2][M];
double l[N];

int main(){

    IO

    int t , n;
    map<int , string> mp;
    string s;

    cin >> t >> n;

    for(int i=0; i<n; i++) cin >> s >> m[i] >> h[i] , l[i] = (double)(m[i])/(double)(h[i]) , mp[i] = s;

    for(int j=0; j<=t; j++){

        if(j >= h[0]) dp[0][j] = m[0] , mx[0][j] = 0;
        else dp[0][j] = 0 , mx[0][j] = -1;

    }

    int ind = 1;

    for(int i=1; i<n; i++){

        while(h[i] > t) i++;

        for(int j=t; j>=0; j--){

            if(j - h[i] >= 0){

                int no = dp[1 - ind][j] , yes = dp[1 - ind][j - h[i]] + m[i];
                int nomx = mx[1 - ind][j] , yesmx = mx[1 - ind][j - h[i]];

                if(no >= yes){

                    dp[ind][j] = no;
                    mx[ind][j] = nomx;

                }else{

                    dp[ind][j] = yes;

                    if(yesmx != -1 && ( l[yesmx] > l[i] || (l[yesmx] == l[i] && yesmx < i))) mx[ind][j] = yesmx;
                    else mx[ind][j] = i;

                }

            }else{

                dp[ind][j] = dp[1 - ind][j];
                mx[ind][j] = mx[1 - ind][j];

            }

        }

        ind = 1 - ind;

    }

    cout << dp[1 - ind][t] << '\n' << mp[mx[1 - ind][t]] << '\n';

    return 0;

}