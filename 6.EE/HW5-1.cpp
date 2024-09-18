#include <iostream>
#include <stack>
#include <string>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

stack<string> temp;
stack<int> st;

int f(int x){ return 5 * x - 7; }

int g(int x , int y){ return 3 * x + 2 * y - 10; }

int h(int x, int y , int z){ return 6 * x + 10 * y - 9 * z + 87; }

int main(){

    IO

    int n;
    cin >> n;

    string s;

    for(int i=0; i<n; i++){

        cin >> s;
        temp.push(s);
        
    }

    while(temp.size()){

        if(temp.top() == "f"){

            int n1 = st.top();
            st.pop();

            st.push(f(n1));

        }else if(temp.top() == "g"){

            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();

            st.push(g(n1 , n2));

        }else if(temp.top() == "h"){

            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            int n3 = st.top();
            st.pop();

            st.push(h(n1 , n2 , n3));

        }else{

            st.push(stoi(temp.top()));

        }

        temp.pop();

    }

    cout << st.top() << '\n';

    return 0;

}