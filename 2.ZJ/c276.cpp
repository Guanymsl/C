#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

int main(){

    IO

    string ans;
    cin >> ans;

    int n;
    cin >> n;

    while(n--){

        vector<char> va , vg;

        int a = 0 , b = 0;

        string guess;
        cin >> guess;

        for(int i=0; i<4; i++){

            if(ans[i] == guess[i]) a++;
            else va.pb(ans[i]) , vg.pb(guess[i]);

        }

        sort(va.begin() , va.end());
        sort(vg.begin() , vg.end());

        int inda = 0 , indg = 0;

        while(indg < (int)vg.size() && inda < (int)va.size()){

            if(vg[indg] == va[inda]) b++ , indg++ , inda++;
            else if(vg[indg] > va[inda]) inda++;
            else indg++;

        }

        cout << a << "A" << b << "B\n";

        va.clear();
        vg.clear();
        
    }

    return 0;

}