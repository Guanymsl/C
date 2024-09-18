#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    unsigned int n;
    cin >> n;

    uint8_t *p = (uint8_t*)&n;

    p += 3;

    for(int i=0; i<4; i++) cout << (int)*p << '\n' , p--;

    return 0;

}