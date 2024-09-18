#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

char a[47] = {'`','1','2','3','4','5','6','7','8','9','0','-','=','Q','W','E','R','T','Y','U','I','O','P','[',']','\\','A','S','D','F','G','H','J','K','L',';','\'','Z','X','C','V','B','N','M',',','.','/'};

int main(){

    string s;

    while(getline(cin,s) && !cin.eof()){

        int l = s.length();

        for(int i=0; i<l; i++){

            if(s[i] == ' ') cout << " ";
            else for(int j=0; j<47; j++) if(s[i] == a[j]) cout << a[j-1];

        }

        cout << '\n';

    }

    return 0;

}