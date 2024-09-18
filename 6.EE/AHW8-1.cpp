#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

int main(){

    IO

    vector<int> aset , bset;

    int a , b , temp;
    cin >> a >> b;

    for(int i=0; i<a; i++){

        cin >> temp;
        aset.pb(temp);

    }

    for(int i=0; i<b; i++){

        cin >> temp;
        bset.pb(temp);

    }

    char op;
    cin >> op;

    if(op == 'X'){

        vector<int> l , r;
        set<int> ans;

        for(int i=0; i<a; i++){

            int j;
            for(j=0; j<b; j++) if(aset[i] == bset[j]) break;
            if(j == b) l.pb(aset[i]);

        }

        for(int i=0; i<b; i++){

            int j;
            for(j=0; j<a; j++) if(bset[i] == aset[j]) break;
            if(j == a) r.pb(bset[i]);

        }

        for(int i=0; i<(int)l.size(); i++) ans.insert(l[i]);
        for(int i=0; i<(int)r.size(); i++) ans.insert(r[i]);

        set<int>::reverse_iterator it;
        for(it = ans.rbegin(); it!=ans.rend(); it++) cout << *it << " ";
        cout << '\n';

    }else if(op == 'J'){

        set<int> u , d;

        for(int i=0; i<a; i++){

            for(int j=0; j<b; j++){

                if(aset[i] == bset[j]){
                    
                    u.insert(aset[i]);
                    break;

                }

            }

        }

        for(int i=0; i<a; i++) d.insert(aset[i]);
        for(int i=0; i<b; i++) d.insert(bset[i]);

        cout << fixed << setprecision(2) << (double)u.size() / (double) d.size() << '\n';

    }else{

        set<int> ex;

        for(int i=0; i<a; i++){

            for(int j=0; j<b; j++){

                if(aset[i] == bset[j]){

                    ex.insert(aset[i]);
                    break;

                }

            }

        }

        if(ex.size() == 0) cout << "True\n";
        else cout << "False\n";

    }

    return 0;

}