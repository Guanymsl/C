#include <iostream>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    cout << "PERFECTION OUTPUT\n";

    int n;

    while(cin >> n && n != 0){

        int cnt = 0;

        for(int i=1; i<n; i++) if(n % i == 0) cnt += i;

        cout << right << setw(5) << n << "  ";

        if(cnt == n) cout << "PERFECT\n";
        else if(cnt > n) cout << "ABUNDANT\n";
        else cout << "DEFICIENT\n";

    }

    cout << "END OF OUTPUT\n";

    return 0;

}