#include <iostream>
#include <stack>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

stack<int> fix;
stack<int> station;
vector<int> b;

int main(){

    IO

    int n ,m;
    cin >> n >> m;

    for(int i=0; i<n; i++){

        int num;
        cin >> num;
        b.pb(num);

    }

    int a = n;
    
    while(a != 0){

        //cout << "a = " << a << '\n';

        int it = -1;

        for(int i=0; i<(int)b.size(); i++){

            if(b[i] == a){

                it = i;
                break;

            }

        }

        //cout << "it = " << it << '\n';

        if(it >= 0){

            int bs = b.size();

            //cout << "it = " << it << '\n';

            for(int i=bs-1; i>=it; i--){

                station.push(b[i]);
                b.erase(b.begin() + i);

            }

            station.pop();

            //cout << "I'm here\n";

            //cout << "station size = " << station.size() << '\n';

        }else{

            //cout << "I'm here 2\n";

            while(station.top() != a){

                fix.push(station.top());
                station.pop();
    
            }

            station.pop();

            if((int)fix.size() > m){

                cout << "no\n";
                break;

            }

            //cout << "fix size = " << fix.size() << '\n';
            //cout << "station size = " << station.size() << '\n';

            while(fix.size() != 0){

                station.push(fix.top());
                fix.pop();

            }
            
            //cout << "station top = " << station.top() << '\n';

        }

        a--;

    }

    if(a == 0) cout << "yes\n";

    return 0;

}