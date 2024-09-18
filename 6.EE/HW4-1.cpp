#include <iostream>
#include <cmath>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){
	
	IO
	
	double num;
	int dig;
	
	cin >> num >> dig;
	
	int s = floor(num * pow(10 , (-1) * dig + 1));
	
	if(dig >= 0){

        if(s % 10 >= 4) s = s - s % 10 + 10;
	    else s = s - s % 10;

        int ans = s / pow(10 , (-1) * dig + 1);

        cout << ans << '\n';

    }else{

        if(s % 10 == 4) num += 2 * pow(10 , dig - 1);
        else if(s % 10 != 9 && s % 10 != 0) num += pow(10 , dig - 1);

        cout << fixed << setprecision((-1) * dig) << num << '\n';

    }
	
	return 0;
	
}