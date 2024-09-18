
#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    for(int i=3; i<=200; i++){

        for(int j=2; j<i; j++){

            for(int k=j; k<=cbrt(pow(i , 3) - pow(j , 3)); k++){

                for(int l=k; l<=cbrt(pow(i , 3) - pow(j , 3) - pow(k , 3)); l++){

                    if(pow(i , 3) == pow(j , 3) + pow(k , 3) + pow(l , 3)) cout << "Cube = " << i << ", Triple = (" << j << "," << k << "," << l << ")\n";
                
                }

            }

        }

    }

    return 0;

}