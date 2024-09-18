#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int SA , SP , J1 , J2 , J3 , N;
    int pz[5] = {40000 , 10000 , 4000 , 1000 , 200};
    
    cin >> SA >> SP >> J1 >>  J2 >> J3 >> N;

    if(SA - N == 0) cout << "Congratulations! You win 10000000 dollars.\n";
    else if (SP - N ==0) cout << "Congratulations! You win 2000000 dollars.\n";
    else if(J1 - N == 0 || J2 - N == 0 ||J3 - N ==0) cout << "Congratulations! You win 200000 dollars.\n";
    else{

        int i;
        for(i=0; i<5; i++){

            int p = pow(10 , 7-i);

            if((J1 - N) % p == 0 ||(J2 - N) % p == 0 || (J3 - N) % p == 0){

                cout << "Congratulations! You win " << pz[i] << " dollars.\n";
                break;

            }

        }

        if(i == 5) cout << "No prize. Better luck next time.\n";

    }

    return 0;

}