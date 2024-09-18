#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n;
    cin >> n;

    while(n--){

        char ch;
        int m , n;

        cin >> ch >> m >> n;

        if(ch == 'r') cout << min(m , n) << '\n';
        else if(ch == 'K') cout << ((m + 1) / 2) * ((n + 1) / 2) << '\n';
        else{

            int bd[m][n];

            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++) bd[i][j] = 0;

            }

            if(ch == 'k'){

            }else if(ch == 'Q'){

            }

        }

    }

    return 0;

}