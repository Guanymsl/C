#include <iostream>
#include <cmath>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

double p , q , r , s , t , u;

double add(double x){

    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;

}

int main(){

    IO

    while(cin >> p >> q >> r >> s >> t >> u && !cin.eof()){

        double ll = 0 , rr = 1 , mid , sum;

        while(true){

            if(add(0) < 0 || add(1) > 0){
                
                cout << "No solution\n";
                break;

            }

            mid = (ll+rr)/2;

            sum = add(mid);
            
            if(abs(sum)<1e-6) break;

            if(sum == 0) break;

            if(sum > 0) ll = mid;
            else rr = mid;

        }

        if(add(0)*add(1) <= 0) cout << fixed << setprecision(4) << mid << '\n';

    }

    return 0;

}