#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    string s;
    getline(cin , s);

    int m , n;
    cin >> m >> n;
    cin.get();

    string pic[m];

    for(int i=0; i<m; i++){
        getline(cin , pic[i]);
    }

    int ind = 0 , l = s.length();

    for(int i=0; i<m; i++){
        
        for(int j=0; j<n; j++){

            if(pic[i][j] == '#'){

                pic[i][j] = s[ind];

                ind = (ind + 1) % l;
                while(s[ind] == ' ') ind = (ind + 1) % l;

            }else pic[i][j] = ' ';

        }

    }

    for(int i=0; i<m; i++){
        cout << pic[i] << '\n';
    }

    return 0;

}