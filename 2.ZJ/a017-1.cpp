#include <iostream>

#include <cstring>
#include <cstdlib>
#include <cmath>

#include <stack>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

vector<string> v;

int parentheses(int , int&);

int multiply(int init , int ind , int& end){

    int sign = 1;

    while(ind < (int)v.size()){

        if(v[ind] == "*") sign = 1;
        else if(v[ind] == "/") sign = -1;
        else if(v[ind] == "%") sign = 0;
        else if(v[ind] == "(") init *= pow(parentheses(ind + 1 , ind) , sign);
        
        if(isdigit(v[ind][0])){

            if(sign == 0) init %= (stoi(v[ind]));
            else init *= pow(stoi(v[ind]) , sign);

        }

        if(v[ind + 1] == "+" || v[ind + 1] == "-" || v[ind + 1] == ")") break;

        ind++;

    }

    end = ind;

    return init;

}

int parentheses(int ind , int& end){

    stack<int> temp;

    int sign = 1 , sum = 0;

    while(ind < (int)v.size()){

        if(v[ind] == ")") break;

        if(isdigit(v[ind][0])) temp.push(sign * stoi(v[ind]));

        if(v[ind] == "+") sign = 1;
        else if(v[ind] == "-") sign = -1;
        else if(v[ind] == "*" || v[ind] == "/" || v[ind] == "%"){

            int top = multiply(temp.top() , ind , ind);
            temp.pop();
            temp.push(top);

        }else if(v[ind] == "("){

            int top = sign * parentheses(ind + 1 , ind);
            temp.push(top);

        }

        ind++;

    }

    while(temp.size()) sum += temp.top() , temp.pop();

    end = ind;

    return sum;

}

int main(){

    IO

    string s;

    while(getline(cin , s) && !cin.eof()){

        while(true){

            v.pb(s.substr(0, s.find(" ")));
            s = s.substr(s.find(" ") + 1 , s.length() - 1);

            if ((int)s.find(" ") == -1) {

                v.pb(s);
                break;

            }

        }

        v.pb(")");

        int ind = 0 , ans = parentheses(0 , ind);

        cout << ans << '\n';

        v.clear();

    }

    return 0;

}