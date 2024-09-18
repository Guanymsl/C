#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

bool equ = false;

int getOperator(char c){

    if(c == '/') return 1;
    else if(c == '%') return 2;
    else if(c == 'c') return 3;
    else return 4;

}

bool compare(string a , string b){

    int la = a.length() , lb = b.length();

    if(la > lb) return true;
    if(la < lb) return false;

    for(int i=0; i<la; i++){

        if(a[i] > b[i]) return true;
        else if(a[i] < b[i]) return false;

    }

    equ = true;

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

string calculate(string a , string b , int op){

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

    if(op == 1) return ans;
    else return a;

}

int main(){

    IO

    string a , b;
    char opc;

    cin >> a >> b >> opc;

    int op = getOperator(opc);

    if(op == 3){

        bool comp = compare(a , b);

        if(equ) cout << "s1 is equal to s2\n";
        else if(comp) cout << "s1 is greater than s2\n";
        else cout << "s1 is less than s2\n";

    }else if(op == 4){

        cout << "Invalid operator\n";

    }else{

        string ans = calculate(a , b , op);
        int lans = ans.length();

        bool swi = false;

        for(int i=0; i<lans; i++){

            if(ans[i] != '0') swi = true;
            if(swi) cout << ans[i];

        }

        cout << '\n';

    }

    return 0;

}