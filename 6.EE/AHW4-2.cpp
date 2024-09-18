#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    int h , w;
    cin >> h >> w;

    if(h % 2 == 0) cout << "No such rhombus.\n";
    else if(2 * w > h) cout << "Not a hollow rhombus.\n";
    else{

        for(int i=0; i<h; i++){

            int blk = abs(i - h / 2);
            int str = h - 2 * blk;

            for(int j=0; j<blk; j++) cout << " ";

            if(str < 2 * w) for(int j=0; j<str; j++) cout << "*";
            else{

                for(int j=0; j<w; j++) cout << "*";
                for(int j=0; j<str-2*w; j++) cout << " ";
                for(int j=0; j<w; j++) cout << "*";

            }

            for(int j=0; j<blk; j++) cout << " ";

            cout << '\n';

        }

    }

    return 0;

}