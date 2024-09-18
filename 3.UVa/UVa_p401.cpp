#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define mp make_pair
#define pcc pair<char , char>
#define f first
#define s second

using namespace std;

pcc m[21] = {mp('A','A'),mp('E','3'),mp('H','H'),mp('I','I'),mp('J','L'),mp('L','J'),mp('M','M'),mp('O','O'),mp('S','2'),mp('T','T'),mp('U','U'),mp('V','V'),mp('W','W'),mp('X','X'),mp('Y','Y'),mp('Z','5'),mp('1','1'),mp('2','S'),mp('3','E'),mp('5','Z'),mp('8','8')};

int main(){

    IO

    string s;

    while(cin >> s && !cin.eof()){

        int l = s.length();

        int pan = 1 , mir = 1;

        for(int i=0; i<(l+1)/2; i++){

            if(pan == 1) if(s[l-i-1] != s[i]) pan = 0;

            if(mir == 1){

                int j;

                for(j=0; j<21; j++) if(s[i] == m[j].f && s[l-i-1] == m[j].s) break;

                if(j == 21) mir = 0;

            }

            if(pan == 0 && mir == 0) break;

        }

        int ans = pan + 2*mir;

        cout << s;

        switch(ans){

            case 0:
                cout<<" -- is not a palindrome.";
                break;

            case 1:
                cout<<" -- is a regular palindrome.";
                break;

            case 2:
                cout<<" -- is a mirrored string.";
                break;

            case 3:
                cout<<" -- is a mirrored palindrome.";
                break;

        }

        cout << '\n' << '\n';

    }

    return 0;

}