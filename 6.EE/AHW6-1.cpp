#include <iostream>
#include <algorithm>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back
#define pii pair<int , int>
#define mp make_pair
#define ff first
#define ss second

using namespace std;

vector<pii> ab;
vector<string> vis;

bool valid(int d1 , int d2 , int d3 , int d4){

    if(d1 != d2 && d1 != d3 && d1 != d4 && d2 != d3 && d2 != d4 && d3 != d4) return true;
    else return false;

}

pii answer(string s1 , string s2){

    vector<int> vs1 , vs2;

    int a = 0 , b = 0;

    for(int j=0; j<4; j++){

        if(s1[j] == s2[j]) a++;
        else vs1.pb((int)(s1[j]-'0')) , vs2.pb((int)(s2[j]-'0'));

    }

    sort(vs1.begin() , vs1.end());
    sort(vs2.begin() , vs2.end());

    int ind = 0 , cur = 0 , size = vs1.size();

    while(ind < size && cur < size){

        if(vs2[ind] < vs1[cur]) ind++;
        else if(vs2[ind] > vs1[cur]) cur++;
        else cur++ , ind++ , b++;

    }

    return mp(a , b);

}

int main(){

    string s;
    cin >> s;

    for(int i=123; i<=9876; i++){

        //cout << "i = " << i << '\n';

        int d1 = i/1000 , d2 = i % 1000 / 100 , d3 = i % 100 / 10 , d4 = i % 10;

        if(!valid(d1 , d2 , d3 , d4)) continue;

        //cout << "I'm here!\n";

        string temp = "0";
        temp += (char)(d1 + 48) , temp += (char)(d2 + 48) , temp += (char)(d3 + 48) , temp += (char)(d4 + 48);
        temp = temp.substr(1 , 5);

        //cout << "temp = " << temp << '\n';

        bool yes = true;

        //cout << "vis.size() = " << vis.size() << '\n';

        for(int j=0; j<(int)(vis.size()); j++){

            if(answer(vis[j] , temp).ff != ab[j].ff || answer(vis[j] , temp).ss != ab[j].ss){

                yes = false;
                break;
                
            }

        }

        //cout << "I'm here!\n";

        int a = 0 , b = 0;

        if(yes){

            a = answer(s , temp).ff , b = answer(s , temp).ss;

            if(a == 4 && b == 0) cout << temp << '\n' << "Bingo!\n";
            else{

                cout << temp << '\n';
                cout << a << "A" << b << "B\n";
                vis.pb(temp);
                ab.pb(mp(a , b));

            }

        }

        if(a == 4 && b == 0) break;

    }

    return 0;

}