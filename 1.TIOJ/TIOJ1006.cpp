#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

bool compare(string a , string b){

    int la = a.length() , lb = b.length();

    if(la > lb) return true;
    if(la < lb) return false;

    for(int i=0; i<la; i++){

        if(a[i] > b[i]) return true;
        else if(a[i] < b[i]) return false;

    }

    return true;

}

string subtract(string a , string b){

    int la = a.length();

    string ans;

    for(int i=0; i<la; i++) ans += "0";

    for(int i=la-1; i>=0; i--){

        if(a[i] >= b[i]) ans[i] += (int)(a[i] - b[i]);
        else{

            a[i - 1]--;
            ans[i] += (int)(a[i] - b[i] + 10);

        }

    }

    return ans;

}

string calculate(string a , string b){

    string ans;
    
    a = "0" + a;

    int la = a.length() , lb = b.length();

    for(int i=la-lb; i>=1; i--){

        ans += "0" ;
        int lans = ans.length();

        while(compare(a.substr(la - lb - i , lb + 1) , "0" + b)){

            a = a.substr(0 , la - lb - i) + subtract(a.substr(la - lb - i , lb + 1) , "0" + b) + a.substr(la - i + 1 , i);
            ans[lans - 1]++;

        }

    }

    return ans;

}

int main(){

    IO

    string a , b;
    cin >> a >> b;

    string ans = calculate(a , b);
    int lans = ans.length();

    bool swi = false;

    for(int i=0; i<lans; i++){

        if(ans[i] != '0') swi = true;
        if(swi) cout << ans[i];

    }

    if(ans == "") cout << 0;

    cout << '\n';

    return 0;

}