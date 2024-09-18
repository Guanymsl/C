#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 1e2 + 5;

int bd[N][N];

int main(){

    IO

    int m , n , k;
    cin >> m >> n >> k;

    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++) cin >> bd[i][j];
        
    }

    int ans1 = 0 , ans2 = 0;

    for(int i=0; i<m; i++){

        int cnt1 = 0 , cnt2 = 0 , mx1 = 0 , mx2 = 0;

        for(int j=0; j<n; j++){

            if(bd[i][j] == 1) cnt1++ , cnt2 = 0;
            else if(bd[i][j] == 2) cnt2++ , cnt1 = 0;
            else cnt1 = cnt2 = 0;

            mx1 = max(mx1 , cnt1);
            mx2 = max(mx2 , cnt2);

        }

        if(mx1 >= k) ans1 = 1;
        if(mx2 >= k) ans2 = 1;
        if(ans1 * ans2 == 1) break;

    }

    for(int i=0; i<n; i++){

        int cnt1 = 0 , cnt2 = 0 , mx1 = 0 , mx2 = 0;

        for(int j=0; j<m; j++){

            if(bd[j][i] == 1) cnt1++ , cnt2 = 0;
            else if(bd[j][i] == 2) cnt2++ , cnt1 = 0;
            else cnt1 = cnt2 = 0;

            mx1 = max(mx1 , cnt1);
            mx2 = max(mx2 , cnt2);

        }

        if(mx1 >= k) ans1 = 1;
        if(mx2 >= k) ans2 = 1;
        if(ans1 * ans2 == 1) break;

    }

    for(int i=0; i<m-k+1; i++){

        int cnt1 = 0 , cnt2 = 0 , mx1 = 0 , mx2 = 0;

        for(int l=0; (i+l)<m && l<n; l++){

            if(bd[i + l][l] == 1) cnt1++ , cnt2 = 0;
            else if(bd[i + l][l] == 2) cnt2++ , cnt1 = 0;
            else cnt1 = cnt2 = 0;

            mx1 = max(mx1 , cnt1);
            mx2 = max(mx2 , cnt2);

        }

        if(mx1 >= k) ans1 = 1;
        if(mx2 >= k) ans2 = 1;
        if(ans1 * ans2 == 1) break;

    }

    for(int i=0; i<m-k+1; i++){

        int cnt1 = 0 , cnt2 = 0 , mx1 = 0 , mx2 = 0;

        for(int l=0; (i+l)<m && (n-l-1)>0; l++){

            if(bd[i+l][n-l-1] == 1) cnt1++ , cnt2 = 0;
            else if(bd[i+l][n-l-1] == 2) cnt2++ , cnt1 = 0;
            else cnt1 = cnt2 = 0;

            mx1 = max(mx1 , cnt1);
            mx2 = max(mx2 , cnt2);

        }

        if(mx1 >= k) ans1 = 1;
        if(mx2 >= k) ans2 = 1;
        if(ans1 * ans2 == 1) break;

    }

    for(int i=1; i<n-k+1; i++){

        int cnt1 = 0 , cnt2 = 0 , mx1 = 0 , mx2 = 0;

        for(int l=0; (i+l)<n && l<m; l++){

            if(bd[l][i+l] == 1) cnt1++ , cnt2 = 0;
            else if(bd[l][i+l] == 2) cnt2++ , cnt1 = 0;
            else cnt1 = cnt2 = 0;

            mx1 = max(mx1 , cnt1);
            mx2 = max(mx2 , cnt2);

        }

        if(mx1 >= k) ans1 = 1;
        if(mx2 >= k) ans2 = 1;
        if(ans1 * ans2 == 1) break;

    }

    for(int i=n-2; i>=k-1; i--){

        int cnt1 = 0 , cnt2 = 0 , mx1 = 0 , mx2 = 0;

        for(int l=0; (i-l)>=0 && l<m; l++){

            if(bd[l][i-l] == 1) cnt1++ , cnt2 = 0;
            else if(bd[l][i-l] == 2) cnt2++ , cnt1 = 0;
            else cnt1 = cnt2 = 0;

            mx1 = max(mx1 , cnt1);
            mx2 = max(mx2 , cnt2);

        }

        if(mx1 >= k) ans1 = 1;
        if(mx2 >= k) ans2 = 1;
        if(ans1 * ans2 == 1) break;

    }

    if(ans1 == 1){

        if(ans2 == 1) cout << "invalid\n";
        else cout << "black\n";

    }else{

        if(ans2 == 1) cout << "white\n";
        else cout << "none\n";

    }

    return 0;

}