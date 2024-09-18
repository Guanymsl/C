#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

#define pic pair<int , char>
#define mp make_pair
#define f first
#define s second

using namespace std;

pic alp[52];

int main(){

    IO

    string s;

    while(getline(cin , s)){

        for(int i=0; i<26; i++) alp[i] = mp(0 , (char)(65+i));
        for(int i=0; i<26; i++) alp[i+26] = mp(0 , (char)(97+i));

        int l = s.length() , m = 0;

        for(int i=0; i<l; i++){

            int ascii = (int)s[i];

            if(ascii >= 65 && ascii <=90) alp[ascii-65].f++ , m = max(m , alp[ascii-65].f);
            else if(ascii >= 97 && ascii <=122) alp[ascii-71].f++ , m = max(m , alp[ascii-71].f);
            
        }

        for(int i=0; i<52; i++) if(alp[i].f == m) cout << alp[i].s;

        cout << " " << m << '\n';

    }

    return 0;

}