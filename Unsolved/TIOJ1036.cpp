#include <iostream>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

const int N = 1e7 + 5;
vector<int> p;

int main(){

    IO

    int* prime = new int[N];

    prime[1] = 0;
    prime[2] = 1;
    prime[3] = prime[4] = 2;
    prime[5] = prime[6] = 3;
    prime[7] = 4;

    int cnt = 4 , sqrt = 1;

    p.pb(2) , p.pb(3) , p.pb(5) , p.pb(7);

    for(int i=1; i<=N/12; i++){

        prime[12 * i - 4] = prime[12 * i - 3] = prime[12 * i - 2] = cnt;

        if((12 * i + 7) >= (p[sqrt + 1]) * (p[sqrt + 1])) sqrt++;

        int s1 = 1 , s2 = 1 , s3 = 1 , s4 = 1;

        for(int j=2; j<=sqrt; j++){

            if(s1 && (12 * i - 1) % p[j] == 0) s1 = 0;

            if(s2 && (12 * i + 1) % p[j] == 0) s2 = 0;

            if(s3 && (12 * i + 5) % p[j] == 0) s3 = 0;

            if(s4 && (12 * i + 7) % p[j] == 0) s4 = 0;

            if(!s1 && !s2 && !s3 && !s4) break;

        }

        if(s1) p.pb(12 * i - 1);
        if(s2) p.pb(12 * i + 1);
        if(s3) p.pb(12 * i + 5);
        if(s4) p.pb(12 * i + 7);

        cnt += s1;

        prime[12 * i - 1] = prime[12 * i] = cnt;

        cnt += s2;

        prime[12 * i + 1] = prime[12 * i + 2] = prime[12 * i + 3] = prime[12 * i + 4] = cnt;

        cnt += s3;

        prime[12 * i + 5] = prime[12 * i + 6] = cnt;

        cnt += s4;

        prime[12 * i + 7] = cnt;

    }

    prime[N - 2] = prime[N - 1] = prime[N] = cnt;

    int m;
    cin >> m;

    while(m--){

        int num;
        cin >> num;

        cout << prime[num] <<'\n';

    }

    delete []prime;

    return 0;

}