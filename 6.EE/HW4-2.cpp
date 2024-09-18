#include <iostream>
#include <cmath>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){
	
	IO
	
	int n;
	cin >> n;
	
	if(n % 2 == 0) cout << "No such rhombus.\n";
	else{
		
		for(int i=0; i<n; i++){
			
			for(int j=0; j<abs(i-(n/2)); j++) cout << " ";
			for(int j=0; j<n-2*abs(i-(n/2)); j++) cout << "*";
			for(int j=0; j<abs(i-(n/2)); j++) cout << " ";
			cout << '\n';
			
		}
		
	}
	
	return 0;
	
}