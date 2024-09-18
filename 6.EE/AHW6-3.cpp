#include <iostream>
#include <stack>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pii pair<int , int>
#define mp make_pair
#define ff first
#define ss second

using namespace std;

int rect[25][25] , ans[25][25];
stack<pii> st;

int main(){

    IO

    int m , n;
    cin >> m >> n;

    for(int j=0; j<n; j++) cin >> rect[0][j] , ans[0][j] = 0;

    for(int i=1; i<m; i++){

        for(int j=0; j<n; j++){

            int input;
            cin >> input;

            if(input == 1) rect[i][j] = rect[i - 1][j] + 1;
            else rect[i][j] = 0;

            ans[i][j] = 0;

        }

    }

    st.push(mp(0 , 0));

    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++){

            while(rect[i][j] < st.top().ff) ans[i][st.top().ss] += rect[i][st.top().ss] * (j - st.top().ss) , st.pop();

            st.push(mp(rect[i][j] , j));

        }

        while(st.size() > 1){

            ans[i][st.top().ss] += rect[i][st.top().ss] * (n - st.top().ss) , st.pop();

        }

    }

    for(int i=0; i<m; i++){

        for(int j=n-1; j>=0; j--){

            while(rect[i][j] < st.top().ff) ans[i][st.top().ss] += rect[i][st.top().ss] * (st.top().ss - j) , st.pop();

            st.push(mp(rect[i][j] , j));

        }

        while(st.size() > 1){

            ans[i][st.top().ss] += rect[i][st.top().ss] * (st.top().ss + 1) , st.pop();

        }

    }

    for(int i=0; i<m; i++){

        for(int j=0 ; j<n; j++) ans[i][j] -= rect[i][j];

    }

    int mx = 0;

    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++) mx = max(mx , ans[i][j]);

    }

    cout << mx << '\n';

    return 0;

}