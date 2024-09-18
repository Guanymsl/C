#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n;
    cin >> n;
    
    while(n--){

        string s;
        cin >> s;

        int l = s.length();

        if(s == "1" || s == "4" || s == "78") cout << "+\n";
        else if(s[l-2] == '3' && s[l-1] == '5') cout << "-\n";
        else if(s[0] == '9' && s[l-1] == '4') cout << "*\n";
        else if(s[0] == '1' && s[1] == '9' && s[2] == '0') cout <<"?\n";
        
    }

    return 0;

}