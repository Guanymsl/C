#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;
    cin >> s;

    int l = s.length();

    int cnt = 1 , mx = 1;

    for(int i=1; i<l; i++){

        if(s[i] == s[i - 1]) cnt++;
        else cnt = 1;

        mx = max(mx , cnt);

    }

    cout << mx << '\n';

    return 0;

}