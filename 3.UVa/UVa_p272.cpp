#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;
    
    int cnt = 1;
    
    while(getline(cin , s) && !cin.eof()){

        int l = s.length();

        for(int i=0; i<l; i++){

            if(s[i] == '\"'){
                
                if(cnt == 1) cout << "``";
                else cout << "\'\'";

                cnt = 1-cnt;

            }

            else cout << s[i];

        }

        cout << '\n';

    }

    return 0;

}