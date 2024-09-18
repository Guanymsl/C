#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string sb , mn;

    while(cin >> sb >> mn){

        int sbl = sb.length() , mnl = mn.length();

        int sbpos = 0  , mnpos = 0;

        while(mnpos < mnl && sbpos < sbl){

            if(mn[mnpos] == sb[sbpos]) sbpos++;
            mnpos++;

        }

        if(sbpos==sbl) cout << "Yes\n";
        else cout << "No\n";

    }

    return 0;
    
}