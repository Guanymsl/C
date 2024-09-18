#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){

        int a , b;
        cin >> a >> b;

        int begin = (a / 2 * 2 + 1) , end = (b + 1) / 2 * 2 - 1;

        cout << "Case " << i << ": " << (begin + end) / 2 * ((end - begin) / 2 + 1) << '\n';
        
    }

    return 0;

}