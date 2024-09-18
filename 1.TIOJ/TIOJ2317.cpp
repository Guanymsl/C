#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second

using namespace std;

vector<pii> v;

int main(){

    int n;

    while(cin >> n){

        string s;
        int y , d;

        for(int i=0; i<n; i++){

            cin >> s >> y >> d;
            v.push_back(mp(y,d));

        }
    
        int m , k;
        cin >> m >> k;

        int cnt = 0;

        for(int i=0; i<n; i++){

            if(m>v[i].f) cnt++;
            else if(m==v[i].f && k>=v[i].s) cnt++;

        }

        cout << cnt << '\n';

    }

}