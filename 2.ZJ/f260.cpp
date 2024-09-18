#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

void print(int* frd , int n){

    for(int i=0; i<n; i++) cout << frd[i] << " ";
    cout << '\n';

}

int query(int x , int* frd){

    if(frd[x] == x) return x;

    frd[x] = query(frd[x] , frd);
    return frd[x];

}

void count(int x , int* frd , int& cnt , bool* check){

    if(frd[x] == x){

        if(!check[x]) cnt++;
        check[x] = true;
        return;

    }

    check[x] = true;
    count(frd[x] , frd , cnt , check);

}

int main(){

    IO

    int n , k;

    while(cin >> n >> k){

        int* frd = new int[n];
        bool* check = new bool[n];

        for(int i=0; i<n; i++) frd[i] = i , check[i] = false;

        while(k--){

            int a , b;
            cin >> a >> b;

            int A = query(a , frd) , B = query(b , frd);

            frd[max(A , B)] = min(A , B);

        }

        int cnt = 0;

        for(int i=n-1; i>=0; i--) if(!check[i]) count(i , frd , cnt , check);

        cout << cnt << '\n';

        delete []check;
        delete []frd;

    }

    return 0;

}