#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;
    stack<int> ans;

    while(cin >> s && !cin.eof()){
    
        if(isdigit(s[s.length()-1])) ans.push(stoi(s));
        else{

            int n2 = ans.top();
            ans.pop();
            int n1 = ans.top();
            ans.pop();

            if(s == "+") ans.push(n1 + n2);
            else if(s == "-") ans.push(n1 - n2);
            else if(s == "*") ans.push(n1 * n2);
            else if(s == "/") ans.push(n1 / n2);

        }

    }

    cout << ans.top() << '\n';

    return 0;

}