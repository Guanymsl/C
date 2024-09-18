#include <iostream>
#include <stack>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

stack<char> st;

int main(){

    string s;

    while(getline(cin , s)){

        int l = s.length();
        
        for(int i=0; i<l; i++){

            if(s[i] != ' ') st.push(s[i]);
            else{

                int sz = st.size();

                for(int j=0; j<sz; j++){

                    cout << st.top();
                    st.pop();

                }

                cout << " ";

            }

        }

        int sz = st.size();

        for(int i=0; i<sz; i++){

            cout << st.top();
            st.pop();

        }

        cout << '\n';

    }

    return 0;

}