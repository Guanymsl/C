#include <iostream>

#define  IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int n;
    cin >> n;

    while(n--){
        
        int f , ans = 0 , a , b , c;
        cin >> f;

        for(int i=0; i<f; i++){

            cin >> a >> b >> c;
            ans+=a*c;
            
        }

        cout << ans << '\n';

    }

    return 0;

}