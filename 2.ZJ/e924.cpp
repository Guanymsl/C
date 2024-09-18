#include <iostream>
#include <stack>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int getnumber(char c){

    if(c == '(') return 1;
    else if(c == '[') return 2;
    else if(c == '<') return 3;
    else if(c == '{') return 4;
    else if(c == '}') return 5;
    else if(c == '>') return 6;
    else if(c == ']') return 7;
    else return 8;

}

int main(){

    IO

    int n;
    cin >> n;

    while(n--){
        
        stack<int> st;

        string s;
        cin >> s;

        int l = s.length();

        bool ans = true;

        for(int i=0; i<l; i++){

            int num = getnumber(s[i]);

            if(st.size() == 0) st.push(num);
            else if(num <= 4) st.push(num);
            else if(num + st.top() == 9) st.pop();
            else break;

        }

        if(st.size() > 0) ans = false;

        if(ans) cout << "Y\n";
        else cout << "N\n";

    }

    return 0;

}