#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string key , text;

    cin >> key;
    getline(cin , text);
    if(text == "") getline(cin , text);

    int tl = text.length() , kl = key.length() , ind = 0;

    for(int i=0; i<tl; i++){

        int t_alp = (int)(text[i] - 'A') , k_alp = (int)(key[ind] - 'A');
        int p = 0;

        if(t_alp >= 32 && t_alp <= 57) t_alp -= 32 , p++;

        if(t_alp >= 0 && t_alp <= 25){

            if(k_alp >= 0 && k_alp <= 25) cout << (char)((t_alp + k_alp) % 26 + 'A');
            else if(k_alp >= 32 && k_alp <= 57) cout << (char)((t_alp + k_alp - 32) % 26 + 'A' + p * 32);

            ind++;
            ind %= kl;

        }else cout << text[i];

    }

    cout << '\n';

    return 0;

}