#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;
    cin >> s;

    char f = s[0];
    int l = s.length();

    for(int i=l-1; i>0; i--){

        if(s[i] == f){

            int j = l - i;

            for(j=0; j<l-i; j++) if(s[j] != s[j + i]) break;

            if(j == l - i) cout << l - i << " ";

        }
    
    }

    cout << '\n';

    return 0;

}