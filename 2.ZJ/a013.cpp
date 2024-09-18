#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

#define psi pair<string , int>
#define pci pair<char , int>
#define mp make_pair
#define f first
#define s second

using namespace std;

psi num[13] = {mp("I",1) , mp("IV",4) , mp("V",5) , mp("IX",9) , mp("X",10) , mp("XL",40) , mp("L",50) , mp("XC",90) , mp("C",100) , mp("CD",400) , mp("D",500) , mp("CM",900) , mp("M",1000)};
pci alp[7] = {mp('I',1) , mp('V',5) , mp('X',10) ,  mp('L',50) ,  mp('C',100) , mp('D',500) , mp('M',1000)};

int d;

void cnt(string s , int ind , int r , int ans){

    if(ind == -1){

        d = ans;
        return;

    }

    if(s[ind] == ' '){

        ans = -ans;
        
        return cnt(s , --ind , 0 , ans);

    }else{

        for(int i=0; i<7; i++){

            if(s[ind] == alp[i].f){

                if(alp[i].s < r) ans -= alp[i].s;
                else ans += alp[i].s;

                r = alp[i].s;

                break;

            }

        }

        return cnt(s , --ind , r , ans);

    }

}

int main(){

    IO

    string s;

    while(getline(cin,s) && s!="#"){

        cnt(s , s.length()-1 , 0 , 0);

        if(d == 0) cout << "ZERO\n";
        else{

            d = abs(d);

            for(int i=12; i>=0; i--){

                for(int j=0; j<d/num[i].s; j++) cout << num[i].f;

                d = d - d / num[i].s * num[i].s;

            }

            cout << '\n';

        }

    }

    return 0;

}