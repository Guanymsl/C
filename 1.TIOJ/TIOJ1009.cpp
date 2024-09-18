#include <iostream>
#include <cstdlib>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int main(){

    IO

    string str , end;

    cin >> str >> end;

    int str_t = stoi(str.substr(0 , 2)) * 3600 + stoi(str.substr(3 , 5)) * 60 + stoi(str.substr(6 , 8)); 
    int end_t = stoi(end.substr(0 , 2)) * 3600 + stoi(end.substr(3 , 5)) * 60 + stoi(end.substr(6 , 8)); 
    int lapse = (end_t - str_t + 86400) % 86400;

    //cout << "str_t / end_t / lapse = " << str_t << " " << end_t << " " << lapse << '\n';

    cout << setw(2) << setfill('0') << lapse / 3600 << ":";
    lapse %= 3600;

    cout << setw(2) << setfill('0') << lapse / 60 << ":";
    lapse %= 60;

    cout << setw(2) << setfill('0') << lapse << '\n';

    return 0;

}