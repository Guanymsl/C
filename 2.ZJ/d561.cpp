#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;
    
    while(cin >> s){

        bool neg = false;

        if(s[0] == '-'){

            s = s.substr(1 , s.length() - 1);
            neg = true;

        }

        if(s.length() == 1) s += ".00";
        else if(s.length() <= 4) for(int i=0; i<(int)(4-s.length()); i++) s += "0";
        else{

            if((int)(s[4] - '0') <= 4) s = s.substr(0 , 4);
            else{

                string ans = s.substr(0 , 4);

                ans[3] = (char)(((int)(s[3] - '0') + 1) % 10 + 48);
                ans[2] = (char)(((int)(s[2] - '0') + (((int)(s[3] - '0') + 1) / 10)) % 10 + 48);
                ans[0] += ((int)(s[2] - '0') + (((int)(s[3] - '0') + 1) / 10)) / 10;

                s = ans;

            }

        }

        if(s == "0.00") cout << s << '\n';
        else{

            if(neg) cout << '-';
            cout << s << '\n';

        }

    }

    return 0;

}