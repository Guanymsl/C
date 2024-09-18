#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

int priority(string s){

    if(s == ")") return 3;
    if(s == "+" || s == "-") return 2;
    if(s == "*" || s == "/" || s == "%") return 1;
    
    return 0;

}

int main(){

    IO

    string s;

    while(getline(cin , s) && !cin.eof()){

        stack<string> ans , op;
        vector<string> v;

        while(true){

            v.pb(s.substr(0, s.find(" ")));
            s = s.substr(s.find(" ") + 1 , s.length() - 1);

            if ((int)s.find(" ") == -1) {

                v.pb(s);
                break;

            }

        }

        int l = v.size();

        for(int i=0; i<l; i++){

            if(!isdigit(v[i][0])){

                int p = priority(v[i]);

                if(op.size() == 0) op.push(v[i]);
                else{

                    if(p == 0) op.push(v[i]);
                    else if(p == 3){

                        while(op.size() != 0 && priority(op.top()) != 0){

                            ans.push(op.top());
                            op.pop();

                        }

                        if(op.size() != 0) op.pop();

                    }else{

                        while(op.size() != 0 && priority(op.top()) <= p && priority(op.top()) != 0){

                            ans.push(op.top());
                            op.pop();

                        }

                        op.push(v[i]);

                    }

                }

            }else ans.push(v[i]);

        }

        while(op.size() != 0){

            ans.push(op.top());
            op.pop();

        }

        stack<string> rev;
        stack<int> temp;

        while(ans.size() != 0){

            rev.push(ans.top());
            ans.pop();

        }

        temp.push(stoi(rev.top()));
        rev.pop();

        while(rev.size() != 0){

            if(isdigit(rev.top()[0])) temp.push(stoi(rev.top())) , rev.pop();
            else{

                int n2 = temp.top();
                temp.pop();
                int n1 = temp.top();
                temp.pop();

                if(rev.top() == "+") temp.push(n1+n2);
                else if(rev.top() == "-") temp.push(n1-n2);
                else if(rev.top() == "*") temp.push(n1*n2);
                else if(rev.top() == "/") temp.push(n1/n2);
                else if(rev.top() == "%") temp.push(n1%n2);

                rev.pop();

            }

        }
        
        cout << temp.top() << '\n';

    }

    return 0;

}