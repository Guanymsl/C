#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back
#define ul unsigned long

using namespace std;

vector<int> va , vb;

int main(){

    IO

    string a , b;
    cin >> a >> b;

    int A = 0 , B = 0;

    for(ul i=0; i<a.length(); i++){

        if(a[i] == b[i]) A++;
        else va.pb((int)(a[i]-'0')) , vb.pb((int)(b[i])-'0');

    }

    sort(va.begin() , va.end());
    sort(vb.begin() , vb.end());

    ul inda = 0 , indb = 0;

    while(indb < vb.size() && inda < va.size()){

        if(vb[indb] == va[inda]) inda++ , indb++ , B++;
        else if(vb[indb] > va[inda]) inda++;
        else indb++;

    }

    cout << A << "A" << B << "B\n";

    return 0;

}