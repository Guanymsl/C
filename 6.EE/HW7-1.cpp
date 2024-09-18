#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pii pair<int , int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

int ascii[300];
vector<pii> v;

int main(){

    IO

    string s;
    getline(cin , s);

    int l = s.length();

    for(int i=0; i<300; i++) ascii[i] = 0;

    for(int i=0; i<l; i++) ascii[(int)s[i]]++;

    for(int i=0; i<300; i++) if(ascii[i] != 0) v.pb(mp(ascii[i] , -i));

    sort(v.begin() , v.end());

    int vs = v.size();

    for(int i=vs-1; i>=0; i--){

        if(isspace((char)(-v[i].ss))) cout << "space";
        else cout << (char)(-v[i].ss);

        cout << ": " << v[i].ff << '\n';

    }

    return 0;

}