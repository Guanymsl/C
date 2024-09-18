#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

vector<int> v;

int main(){

    IO

    int n;

    while(cin >> n && n){

        v.pb(1);

        for(int i=1; i<n; i++) v.pb(0);

        for(int i=1; i<n; i++){

            int ind = 1 , cnt = 0 , num = 0;

            while(v[12]==0){

                if(v[ind]==0) cnt++;

                if(cnt==i){

                    cnt = 0;
                    num++;
                    v[ind] = 1;

                    //for(int j=0; j<n; j++) cout << v[j];
                    //cout<<'\n';

                }

                ind++;
                if(ind==n) ind = 0;

            }

            v.clear();
            v.pb(1);

            for(int i=1; i<n; i++) v.pb(0);

            if(num==n-1){

                cout << i << '\n';
                break;

            }

        }

    }

    return 0;
    
}