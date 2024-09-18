#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

vector<int> v;

int main(){

    IO

    int n , q , ind = 1;

    while(cin >> n >> q && n){

        int marble;

        for(int i=0; i<n; i++){

            cin >> marble;
            v.pb(marble);

        }

        sort(v.begin() , v.end());

        cout << "CASE# " << ind << ":\n";

        for(int i=0; i<q; i++){

            int f;
            cin >> f;

            vector<int>::iterator it = find(v.begin() , v.end() , f);

            if(it != v.end()) cout << f << " found at " << distance(v.begin() , it) + 1 << '\n';
            else cout << f << " not found\n";

        }

        v.clear();
        v.shrink_to_fit();

        ind++;

    }

    return 0;

}