#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pic pair<int , char>
#define mp make_pair
#define s second

using namespace std;

const int N=105;

vector<pic> v;
int ord[N];
char msn[N];

int main(){

    int l , n , m;
    cin >> l >> n >> m;

    for(int i=0; i<n; i++) cin >> ord[i];

    string s;

    for(int i=0; i<l; i++){

        cin >> s;

        for(int j=0; j<n; j++) msn[j] = s[j];

        for(int j=0; j<m; j++){

            for(int k=0; k<n; k++){

                pic p = mp(ord[k],msn[k]);
                v.push_back(p);

            }

            //for(int k=0;k<n;k++) cout<<v[k].first<<v[k].s;

            sort(v.begin(),v.end());

            //for(int k=0;k<n;k++) cout<<v[k].first<<v[k].s;

            for(int k=0; k<n; k++) msn[k] = v[k].s;

            v.clear();

        }

        for(int j=0; j<n; j++ ) cout << msn[j];

        cout << '\n';

    }

}