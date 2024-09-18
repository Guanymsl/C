#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

const int N = 1e3+5;

int code[N] , guess[N];
vector<int> crem , grem;

int main(){

    IO

    int n , round = 1 , temp;
    string s;

    while(cin >> n && n){

        for(int i=0; i<n; i++) cin >> code[i];
        
        cout << "Game " << round << ":\n";

        while(cin >> guess[0] && guess[0]){
          
            int a = 0 , b = 0;

            if(guess[0] == code[0]) a++;
            else crem.pb(code[0]) , grem.pb(guess[0]);

            for(int i=1; i<n; i++){

                cin >> guess[i];

                if(guess[i] == code[i]) a++;
                else crem.pb(code[i]) , grem.pb(guess[i]);

            }

            sort(crem.begin() , crem.end());
            sort(grem.begin() , grem.end());

            int cpos = 0 , gpos = 0;
            while(cpos<n-a && gpos<n-a){

                if(grem[gpos] == crem[cpos]){

                    b++;
                    cpos++;
                    gpos++;

                }else if(grem[gpos] > crem[cpos]) cpos++;
                else gpos++;

            }

            cout << "    (" << a << "," << b << ")\n";

            crem.clear();
            grem.clear();

        }

        for(int i=1; i<n; i++) cin >> temp;

        round++;

    }

    return 0;
}