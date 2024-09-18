#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;
    
    while(cin >> s && s != "0"){

        int l = s.length();

        int odd = 0 , even = 0;

        for(int i = 0; i<l; i+=2) odd += (int)(s[i]-'0');
        for(int i = 1; i<l; i+=2) even += (int)(s[i]-'0');

        cout << s << " is";
        if(abs(odd - even) % 11 != 0) cout << " not";
        cout << " a multiple of 11.\n";

    }

    return 0;

}