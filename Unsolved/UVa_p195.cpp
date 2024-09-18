#include <iostream>
#include <algorithm>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

vector<int> vc , sub;

int main(){

    IO

    int n;
    cin >> n;

    while(n--){

        string s;

        cin >> s;

        int l = s.length();

        for(int i=0; i<l; i++) vc.pb(-(int)(s[i]));

        sort(vc.begin() , vc.end());

        int ind , k = 0;

        while(true){

            for(int i=l-1; i>=0; i--) cout << (char)(-vc[i]);
            cout << '\n';

            for(k=0; k<l-1; k++){

                if(vc[k] < vc[k+1]){

                    ind = k+1;
                    break;

                }

            }

            if(k == l-1) break;

            for(int i=0; i<=ind; i++) sub.pb(vc[i]);

            sort(sub.begin() , sub.end());

            /*for(int i=0; i<sub.size(); i++) cout << (char)(-sub[i]);
            cout << '\n';*/

            vector<int>::iterator it = find(sub.begin() , sub.end() , vc[ind]);

            it--;

            vc[ind] = *it;

            //cout << (char)(-vc[ind]) << '\n';

            //cout << (char)(-*it) << '\n';

            sub.erase(it);

            /*for(int i=0; i<sub.size(); i++) cout << (char)(-sub[i]);
            cout << '\n' << "end" << '\n';*/

            for(int i=0; i<(int)sub.size(); i++) vc[ind-i-1] = sub[ind-i-1];

            sub.clear();

        }

        vc.clear();

    }

    return 0;

}