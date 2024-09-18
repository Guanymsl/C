#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ul unsigned long

using namespace std;

int alp[26];

int main(){

    IO

    int rnd;

    while(cin >> rnd && rnd != -1){

        for(int i=0; i<26; i++) alp[i] = 0;

        string sol , guess;
        cin >> sol >> guess;

        int cnt = 0 , die = 0;

        for(ul i=0; i<sol.length(); i++){

            if(alp[(int)(sol[i]-'a')] == 0) alp[(int)(sol[i]-'a')] = 1 , cnt++;

        }

        //for(int i=0; i<26; i++) cout << alp[i] << " ";
        //cout << '\n';
        //cout << cnt << '\n';

        for(ul i=0; i<guess.length(); i++){

            if(alp[(int)(guess[i]-'a')] == 0) die++;
            else if(alp[(int)(guess[i]-'a')] == 1){

                alp[(int)(guess[i]-'a')] = 2;
                cnt--;

            }

            if(die == 7) break;

        }

        cout << "Round " << rnd << '\n';
        if(cnt == 0) cout << "You win.\n";
        else if(die == 7) cout << "You lose.\n";
        else cout << "You chickened out.\n";

    }

    return 0;

}