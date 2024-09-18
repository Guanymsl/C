#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;
const int N = 25;

vector<int> v;
int ans[N];

int main(){

    IO

    int n;
    cin >> n;

    for(int i=0; i<n; i++){

        int temp;
        cin >> temp;
        ans[i] = temp - 1;

    }

    int temp;

    while(cin >> temp){

        int seq[N];

        seq[temp - 1] = ans[0];

        for(int i=1; i<n; i++){

            int temp;
            cin >> temp;
            seq[temp - 1] = ans[i];

        }

        v.pb(seq[0]);

        int cnt = 1 , mx = 0;

        for(int i=1; i<n; i++){

            if(seq[i] > v.back()){

                v.pb(seq[i]);
                cnt = v.size();

            }else{

                vector<int>::iterator it = lower_bound(v.begin() , v.end() , seq[i]);
                *it = seq[i];

            }

            mx = max(cnt, mx);

        }

        cout << mx << '\n';

        v.clear();

    }

    return 0;

}