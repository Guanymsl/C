#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    int n1 , n2;

    cin >> n1 >> n2;

    int d = n1 - n2;

    cout << d/50 << '\n' << d%50/10 << '\n' << d%10/5 << '\n' << d%5 <<'\n';

    return 0;

}