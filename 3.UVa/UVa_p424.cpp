#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 1e2+5;

int car[N] , ans[N] , add[N];

int main(){

    for(int i=0; i<N; i++) ans[i] = 0;

    string s;

    while(cin >> s && s != "0"){

        for(int i=0; i<N; i++) car[i] = add[i] = 0;
        
        int l = s.length();

        for(int i=l-1; i>=0; i--) add[l-1-i] = (int)(s[i]-'0');

        //for(int i=l-1; i>=0; i--) cout << add[i];
        //cout << '\n';

        for(int i=0; i<N-1; i++){

            car[i+1] = (car[i] + ans[i] + add[i]) / 10;
            ans[i] = (car[i] + ans[i] + add[i]) % 10;

        }

        /*for(int i=N-1; i>=0; i--) cout << ans[i];
        cout << '\n';*/

    }

    int st = 0;

    for(int i=N-1; i>=0; i--){

        if(st == 0){

            if(ans[i] != 0) st = 1 , cout << ans[i];

        }else cout << ans[i];

    }

    cout << '\n';

    return 0;

}