#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int p[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97} , cnt[25] = {};

int main(){

    IO

    int n;
    
    while(cin >> n && n){

        int ed=25;

        for(int i=0; i<25; i++){

            if(p[i]>n){

                ed = i;
                break;

            }

            int k=p[i];

            while(k<=n){

                cnt[i] += n/k;
                k = k*p[i];

            }

        }

        if(n==100) cout << 100;
        else if(n>=10) cout << " " << n;
        else cout << "  " << n;
        cout << "! =";

        for(int i=0; i<ed; i++){

            if(i==15) cout << '\n' << "      ";
            
            cout << " ";

            if(cnt[i]>=10) cout << cnt[i];
            else cout << " " << cnt[i];
            
        }

        cout << '\n';

        for(int i=0; i<25; i++) cnt[i] = 0;

    }

    return 0;

}