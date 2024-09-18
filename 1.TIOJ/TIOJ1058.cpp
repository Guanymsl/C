#include <iostream>
#include <cstdlib>
#include <cstring>

#define IO ios_base::sync_with_stdio(0);

using namespace std;

int main(){

    IO

    string a , b;

    while(cin >> a >> b){

        int adot = a.find('.') , bdot = b.find('.');
        int la = a.length() , lb = b.length();

        if(adot == -1) adot = la;
        if(bdot == -1) bdot = lb;

        //cout << "(adot , bdot) = (" << adot << " , " << bdot << ")\n";

        if(adot > bdot) cout << a << '\n';
        else if(bdot > adot) cout << b << '\n';
        else{

            bool comp = false , fin = false;

            for(int i=0; i<min(la , lb); i++){

                //cout << "a[" << i << "] = " << a[i] << '\n';

                if(a[i] == '.') continue;

                if(a[i] > b[i]){

                    comp = true;
                    break;

                }

                if(a[i] < b[i]){

                    fin = true;
                    break;

                }

            }

            //cout << "comp = " << comp << '\n';

            if(!comp && !fin) if(la > lb) comp = true;

            if(comp) cout << a << '\n';
            else cout << b << '\n';

        }

    }

    return 0;

}