#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;

    while(getline(cin , s)){

        int cnt = 0 , l = s.length() , w = 0;

        for(int i=0; i<l; i++){

            int ascii = (int)s[i];

            if((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) w++;
            else if(w != 0) cnt++ , w = 0;

        }

        cout << cnt << '\n';

    }

    return 0;

}