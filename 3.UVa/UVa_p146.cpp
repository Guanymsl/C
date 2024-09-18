#include <iostream>
#include <algorithm>
#include <vector>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string s;
    
    while(cin >> s && s!="#"){

        int l = s.length();
        int alp[l];

        for(int i=0; i<l; i++) alp[i]=(int)(s[i]-'a');

        int pos = l-1;
        vector<int> v;

        v.push_back(alp[l-1]);

        for(int i=l-1; i>0; i--){

            if(alp[i]<=alp[i-1]){

                pos = i-1;
                v.push_back(alp[i-1]);

            }
            else break;

        }

        if(pos==0) cout << "No Successor\n";
        else if(pos==l-1){

            for(int i=0; i<pos-1; i++) cout << (char)(alp[i]+'a');
            cout << s[l-1] << s[l-2] << '\n';

        }
        else{
            for(int i=0; i<pos-1; i++) cout << (char)(alp[i]+'a');

            sort(v.begin() , v.end());

            vector<int>::iterator it = upper_bound(v.begin() , v.end() , alp[pos-1]);

            cout << (char)(*it+'a');
            v.erase(it);
            v.push_back(alp[pos-1]);

            sort(v.begin() , v.end());

            int vs = v.size();
            for(int i=0; i<vs; i++) cout << (char)(v[i]+'a');

            cout << '\n';

        }
       
    }

    return 0;

}