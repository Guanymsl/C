#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

stack<char> ans , op;

int priority(char c){

    if(c == ')') return 3;
    if(c == '+' || c == '-') return 2;
    if(c == '*' || c == '/') return 1;
    
    return 0;

}

int main(){

    IO

    string s;

    while(getline(cin , s)){

        //cout << "The Input = " << s << '\n';

        int l = s.length();

        //cout << "Length = " << l << '\n';

        for(int i=0; i<l; i++){

            //cout << "The " << i << "'s round of loop\n";
            //cout << "s[i] = " << s[i] << '\n';

            if(isspace(s[i])){

                //cout << "Continue : " << i << '\n';
                continue;

            }else{

                if(!isalpha(s[i])){

                    //cout << "s[" << i << "] is not digit!\n";

                    int p = priority(s[i]);

                    //cout << "s[" << i << "]'s priority = " << p << '\n';
                    
                    if(op.size() == 0) op.push(s[i]);
                    else{

                        if(p == 0) op.push(s[i]);
                        else if(p == 3){

                            while(op.size() != 0 && priority(op.top()) != 0){

                                ans.push(op.top());
                                op.pop();

                            }

                            if(op.size()) op.pop();

                        }else{

                            while(op.size() != 0 && priority(op.top()) <= p && priority(op.top()) != 0){

                                ans.push(op.top());
                                op.pop();

                            }

                            op.push(s[i]);

                        }

                    }

                }else ans.push(s[i]);

            }

        }

        while(op.size() != 0){

            ans.push(op.top());
            op.pop();
        }

        vector<char> rev;

        while(ans.size() != 0){

            rev.pb(ans.top());
            ans.pop();

        }

        for(int i=(int)rev.size()-1; i>=0; i--) cout << rev[i] << " ";
        
        cout << '\n';

    }

    return 0;

}