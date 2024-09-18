#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 1e4+5;

int frd[N];

void print(int n){

    for(int i=1; i<=n; i++) cout << frd[i] << " ";
    cout << '\n';

}

int query(int x){

    if(frd[x] == x) return x;

    frd[x] = query(frd[x]);
    return frd[x];

}

int main(){

    IO

    int n , m , q;
    cin >> n >> m >> q;

    for(int i=1; i<=n; i++) frd[i] = i;

    while(m--){

        int A , B;
        cin >> A >> B;

        int a = query(A) , b = query(B);
        frd[max(a , b)] = min(a , b);

        //print(n);

    }

    while(q--){

        int P , Q;
        cin >> P >> Q;

        if(query(P) != query(Q)) cout << ":(\n";
        else cout << ":)\n";

    }

    return 0;

}