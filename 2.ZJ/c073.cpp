#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back
#define ul unsigned long

using namespace std;

int main(){

    int n;
    cin >> n;

    vector< vector<int> > v(n);

    for(int i=0; i<n; i++) v[i].pb(-1) , v[i].pb(i);

    string s1 , s2;
    int a , b;

    while(cin >> s1){

        if(s1 == "quit") break;
        else{

            cin >> a >> s2 >> b;

            if(a == b || a >= n || b >= n) continue;

            else{

                int anum , apos , bnum , bpos;

                for(int i=0; i<n; i++){

                    for(ul j=1; j<v[i].size(); j++){

                        if(v[i][j] == a) anum = i , apos = j;
                        if(v[i][j] == b) bnum = i , bpos = j;

                    }

                }

                if(s1 == "move"){

                    if(s2 == "onto") v[bnum].insert(v[bnum].begin() + bpos + 1 , a);
                    else v[bnum].pb(a);

                    v[anum].erase(v[anum].begin() + apos);
                    v[anum].shrink_to_fit();

                }
                else if((s2 == "onto" && (anum != bnum || apos > bpos)) || (s2 == "over" && anum != bnum)){

                    int vs = v[anum].size() , cnt = 1;

                    for(int i=apos; i<vs; i++){
                        
                        if(s2 == "onto") v[bnum].insert(v[bnum].begin() + bpos + cnt , v[anum][i]);
                        else v[bnum].pb(v[anum][i]);

                        cnt++;
                
                    }

                    v[anum].erase(v[anum].begin() + apos , v[anum].begin() + vs);
                    v[anum].shrink_to_fit();
    
                }

            }

        }

    }  
    
    for(int i=0; i<n; i++){

        cout << i << ":";

        for(ul j=1; j<v[i].size(); j++){

            cout << " " << v[i][j];

        }

        cout << '\n';

    }

    return 0;

}