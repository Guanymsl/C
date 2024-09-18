#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N=1e4+5;

int H[N];

int main(){
    
    IO

    int l , h , r;
    int end = 0;

    for(int i=0; i<N; i++) H[i] = 0;

    while(cin >> l >> h >> r && !cin.eof()) for(int i=l; i<r; i++) H[i] = max(H[i],h) , end = max(end,r); 

    //for(int i=1; i<=end; i++) cout << H[i] << " ";
    
    int hei = 0;

    for(int i=1; i<=end; i++){

        //if(H[i]==0 && H[i-1]!=0) cout << i-1 << " " << 0 <<" " , hei = 0;

        if(H[i]!=hei){

            cout << i << " " << H[i];
            if(i!=end) cout<<" ";
            hei = H[i];

        }

    }

    cout << '\n';

    return 0;

}