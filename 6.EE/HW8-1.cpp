#include <iostream>
#include <stack>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

stack<int> st;

int getNum(char c){

    if(c == '(') return 1;
    else if(c == '[') return 2;
    else if(c == '{') return 3;
    else if(c == '<') return 4;
    else if(c == '>') return 5;
    else if(c == '}') return 6;
    else if(c == ']') return 7;
    else return 8;

}

int main(){

    string s;
    cin >> s;

    int l = s.length();

    for(int i=0; i<l; i++){

        int type = getNum(s[i]);

        if(st.size() == 0) st.push(type);
        else if(type <= 4) st.push(type);
        else if(st.top() + type != 9) break;
        else st.pop();

    }

    if(st.size() == 0) cout << "pass\n";
    else cout << "not pass\n";

    return 0;

}