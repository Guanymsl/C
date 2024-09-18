#include <iostream>
#include <algorithm>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back
#define pii pair<int , int>
#define mp make_pair
#define f first
#define s second

using namespace std;

vector<pii> ab;
vector<int> vans , vguess;

int main(){

    string ans;
    int n;
    
    cin >> ans >> n;

    for(int i=0; i<n; i++){

        string guess;
        cin >> guess;

        int a = 0 , b = 0;

        for(int j=0; j<4; j++){

            if(ans[j] == guess[j]) a++;
            else vans.pb((int)(ans[j]-'0')) , vguess.pb((int)(guess[j]-'0'));

        }

        sort(vans.begin() , vans.end());
        sort(vguess.begin() , vguess.end());

        int ind = 0 , size = vans.size() , cur = 0;

        while(ind < size && cur < size){

            if(vguess[ind] < vans[cur]) ind++;
            else if(vguess[ind] > vans[cur]) cur++;
            else cur++ , ind++ , b++;

        }

        ab.pb(mp(a , b));

        //cout << "A = " << a << " B = " << b << '\n';

        vans.clear();
        vguess.clear();

    }

    sort(ab.begin() , ab.end());

    if(ab[ab.size() - 1].f == 4 && ab[ab.size() - 1].s == 0) cout << "Bingo!\n";
    else cout << ab[ab.size() - 1].f << "A" << ab[ab.size() - 1].s << "B\n";

}
