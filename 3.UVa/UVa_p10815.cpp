#include <iostream>
#include <cstring>
#include <set>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

set<string> ans;

int main(){

    IO

    string s , temp = "0";
    
    while(getline(cin , s) && !cin.eof()){

        int l = s.length();

        for(int i=0; i<l; i++){

            if(isalpha(s[i])) temp += tolower(s[i]);
            else if(temp != "0") ans.insert(temp.substr(1 , temp.length())) , temp = "0";

            if(isalpha(s[i]) && i == l - 1 && temp != "0") ans.insert(temp.substr(1 , temp.length())) , temp = "0";
            
        }
        
    }
    
    for(set<string>::iterator it=ans.begin(); it!=ans.end(); it++) cout << *it << '\n';

    return 0;

}