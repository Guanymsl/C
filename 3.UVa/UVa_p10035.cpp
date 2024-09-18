#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int sum[11] , add[11] , car[11];

int main(){

    IO

    string s , a;

    while(cin >> s >> a){

        if(s == "0" && a == "0") return 0;

        int sl = s.length() , al = a.length();

        int dig = 10;

        for(int i=sl-1; i>=0; i--) sum[dig] = (int)(s[i]-'0') , dig--;

        dig++;
        while(dig--) sum[dig] = 0;

        dig = 10;
        for(int i=al-1; i>=0; i--) add[dig] = (int)(a[i]-'0') , dig--;

        dig++;
        while(dig--) add[dig] = 0;

        int cnt = 0;

        for(int i=0; i<11; i++) car[i] = 0;

        for(int i=10; i>0; i--){

            if(car[i] + sum[i] + add[i] >= 10){

                cnt++;
                car[i-1] = 1;

            }

        }

        if(cnt==0) cout << "No carry operation.\n";
        else if(cnt==1) cout << "1 carry operation.\n";
        else cout << cnt << " carry operations.\n";

        for(int i=0; i<11; i++) sum[i] = 0 , add[i] = 0;

    }

}