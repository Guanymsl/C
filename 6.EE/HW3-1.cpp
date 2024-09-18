 #include <iostream>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int mer[5] = {59 , 480 , 263 , 1107, 825} , chn[7] = {1000 , 500 , 100 , 50 , 10 , 5 , 1};

int main(){

    IO

    int num , mon;

    cin >> num >> mon;

    if(mon >= mer[num - 1]) cout << "Here is your change:\n";
    else cout << "That's not enough. You still need to pay:\n";
    
    int ret = abs(mon - mer[num - 1]);

    for(int i=0; i<7; i++){

        cout << "$" << setw(4) << left << chn[i];
        cout << " x" << ret / chn[i] << '\n';

        ret = ret % chn[i];

    }

    return 0;

}