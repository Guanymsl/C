#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    int n;
    string s;

    cin >> n;

    getline(cin , s);
    if(s == "")  getline(cin , s);

    int l = s.length();

    for(int i=0; i<l; i++){

        int alp = (int)(s[i]-'a');

        if(alp >= 0 && alp <= 25) cout << (char)(((alp + n) % 26 + 26) % 26 + 'a');
        else cout << s[i];
        
    }

    cout << '\n';

    return 0;

}