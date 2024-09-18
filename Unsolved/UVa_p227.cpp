#include <iostream>
#include <cstring>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int bd[5][5];

int main(){

    IO

    int x , y , ind = 1;

    string s;

    getline(cin , s);

    while(s != "Z"){

        for(int j=0; j<5; j++){
            
            if(s[j] == ' '){

                y = 0 , x = j;
                bd[0][j] = 0;

            }else bd[0][j] = (int)(s[j]);

        }

        for(int i=1; i<5; i++){

            getline(cin , s);

            int l = s.length();

            if(l == 4) 

            for(int j=0; j<5; j++){

                if(s[j] == ' '){

                    y = i , x = j;
                    bd[i][j] = 0;

                }else bd[i][j] = (int)(s[j]);

            }


        }
        
            for(int i=0; i<5; i++){

                for(int j=0; j<5; j++){

                    if(bd[i][j] == 0) cout << " ";
                    else cout << bd[i][j];

                }
            
            cout << '\n';
            
            }

        cin >> s;

        while(s[s.length()-1] != 'O'){

            string t;
            cin >> t;
            s = s + t;

        }

        int l = s.length() , dne = 0;

        cout<<l<<endl;

        cout<<x<<" "<<y<<endl;

        for(int i=0; i<l-1; i++){

            if(s[i] == 'A' && y > 0){

                swap(bd[y][x] , bd[y-1][x]);
                y--;

            }else if(s[i] == 'B' && y < 4){

                //swap(bd[y][x] , bd[y+1][x]);
                y++;

            }else if(s[i] == 'R' && x < 4){

                //swap(bd[y][x] , bd[y][x+1]);
                x++;

            }else if(s[i] == 'L' && x > 0){

                swap(bd[y][x] , bd[y][x-1]);
                x--;

            }else{

                dne = 1;
                break;

            }

            /*for(int i=0; i<5; i++){

                for(int j=0; j<5; j++){

                    if(bd[i][j] == 0) cout << " ";
                    else cout << (char)(bd[i][j]);

                }
            
            cout << '\n';
            
            }*/
            
        }

        cout << "Puzzle #" << ind << ":\n";

        if(dne == 1) cout << "This puzzle has no final configuration.\n";
        else{

            for(int i=0; i<5; i++){

                for(int j=0; j<5; j++){

                    if(bd[i][j] == 0) cout << " ";
                    else cout << (char)(bd[i][j]);

                    if(j != 4) cout << " ";

                }

                cout << '\n';
                
            }

        }

        cout << '\n';

        ind++;

    }

    return 0;

}