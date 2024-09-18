#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;
    int add;

    cin >> s >> add;

    int exp = (int)(s[0] - 'A') + add - 1;
    int lev = ((int)(s[0] - 'C') + 7) % 7;

    cout << (char)('A' + exp % 7) << (int)(s[1] - '0') + (lev + add - 1) / 7 << "\n";

    return 0;

}