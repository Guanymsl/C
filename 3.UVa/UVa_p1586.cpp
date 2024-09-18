#include <iostream>
#include <iomanip>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pcd pair<char , double>
#define mp make_pair
#define f first
#define s second

using namespace std;

pcd ele[4] = {mp('C' , 12.01) , mp('H' , 1.008) , mp('O' , 16) , mp('N' , 14.01)};

int main(){

    IO

    int n;
    cin >> n;

    while(n--){

        string s;
        cin >> s;

        double ans = 0 , p = 0 , cnt = 0;
        int l = s.length();

        s = s + 'Z';

        for(int i=0; i<l; i++){

            int cur = (int)(s[i]-'0') , next = (int)(s[i+1]-'0');

            if(cur > 9){

                for(int j=0; j<4; j++) if(s[i] == ele[j].f) p = ele[j].s;

                //cout << p << '\n';

                if(next > 9) ans += p;

            }else{

                if(next > 9) cnt += cur , ans += p * cnt , cnt = 0;
                else cnt += cur * 10;

                //cout << cnt << '\n'; 

            }

        }

        cout << fixed << setprecision(3) << ans << '\n';

    }

    return 0;

}