#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long

using namespace std;

int main(){

    IO

    ll b1 , g1 , c1 , b2 , g2 , c2 , b3 , g3 , c3;

    while(cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3 && !cin.eof()){
        
        ll sum = b1 + g1 + c1 + b2 + g2 + c2 + b3 + g3 + c3;

        ll bgc , bcg , gbc , gcb , cbg , cgb;
    
        bgc = sum - (b1 + g2 + c3);
        bcg = sum - (b1 + c2 + g3);
        gbc = sum - (g1 + b2 + c3);
        gcb = sum - (g1 + c2 + b3);
        cbg = sum - (c1 + b2 + g3);
        cgb = sum - (c1 + g2 + b3);

        ll ans = min(min(bgc , min(bcg , gbc)) , min(gcb, min(cbg , cgb)));

        if(bcg==ans){
            cout << "BCG " << ans << '\n';
        }else if(bgc==ans){
            cout << "BGC " << ans << '\n';
        }else if(cbg==ans){
            cout << "CBG " << ans << '\n';
        }else if(cgb==ans){
            cout << "CGB " << ans << '\n';
        }else if(gbc==ans){
            cout << "GBC " << ans << '\n';
        }else{
            cout << "GCB " << ans << '\n';
        }

    }

}