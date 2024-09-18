#include <iostream>
#include <vector>
#include <set>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

vector<int> aset , bset;
set<int> ans;

int main(){

    IO

    int a , b;
    cin >> a >> b;

    int temp;

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

    if(op == 'I'){

        for(int i=0; i<a; i++){

            for(int j=0; j<b; j++){

                if(aset[i] == bset[j]){
                    ans.insert(aset[i]);
                    break;
                }

            }

        }

    }else if(op == 'U'){

        for(int i=0; i<a; i++) ans.insert(aset[i]);
        for(int i=0; i<b; i++) ans.insert(bset[i]);

    }else{

        int first;
        cin >> first;

        if(first == 1){

            for(int i=0; i<a; i++){

                int j;
                for(j=0; j<b; j++) if(aset[i] == bset[j]) break;
                if(j == b) ans.insert(aset[i]);

            }

        }else{

            for(int i=0; i<b; i++){

                int j;
                for(j=0; j<a; j++) if(bset[i] == aset[j]) break;
                if(j == a) ans.insert(bset[i]);

            }

        }

    }

    int sz = ans.size();

    if(sz == 0) cout << '\n';
    else{

        set<int>::reverse_iterator it;
        for(it = ans.rbegin(); it!=ans.rend(); it++) cout << *it << " ";
        cout << '\n';

    }

    return 0;

}