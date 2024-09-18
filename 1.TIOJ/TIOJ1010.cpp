#include <iostream>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string p , q;
    cin >> p >> q;
    
    int pl = p.length() , ql = q.length() , cnt = 0;

    for(int i=0; i<ql; i++){

        if(q[i] == p[0] && ql - i <= pl){

            for(int j=i; j<ql; j++){

                if(q[j] != p[j-i]){

                    cnt = 0;
                    break;

                }
                else cnt++;
            }

        }

        if(cnt != 0) break;

    }

    cout << cnt << '\n';

    return 0;

}