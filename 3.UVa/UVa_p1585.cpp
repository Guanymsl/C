#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n;
    cin >> n;

    while(n--){

        string s;
        cin >> s;

        int l = s.length() , cnt = 1 , ans = 0;

        for(int i=0; i<l; i++){

            if(s[i] == 'O') ans += cnt , cnt++;
            else cnt = 1 ;

        }

        cout << ans << '\n';

    }

    return 0;
}