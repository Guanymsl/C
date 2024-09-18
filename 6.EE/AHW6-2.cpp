#include <iostream>
#include <cstdlib>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int d_of_m[12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
int dd_of_m[12] = {31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

string day[7] = {"Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" , "Sunday"};
string month[12] = {"JANUARY" , "FEBRUARY" , "MARCH" , "APRIL" , "MAY" , "JUNE" , "JULY" , "AUGUST" , "SEPTEMBER" , "OCTOBER" , "NOVEMBER" , "DECEMBER"};

int len[12] = {7 , 8 , 5 , 5 , 3 , 4 , 4 , 6 , 9 , 7 , 8 , 8};

bool isdd(int y){

    if((y % 4 == 0 && y % 100 != 0 ) || y == 2000) return true;
    else return false;

}

int getdate(int y , int m , int d){
    
    int cnt = 0;

    cnt += (y - 1700) * 365;
    cnt += ((y - 1) / 4) - (1700 / 4) + 1;
    cnt -= (y - 1601) / 100 ;
    if(y > 2000) cnt++;

    for(int i=0; i<m-1; i++) cnt += d_of_m[i];
    cnt += d;

    if(y % 4 == 0 && (y % 100 != 0 || y % 400 == 0) && (m > 2)) cnt++;

    return (cnt + 4) % 7;

}

int getweek(int y , int m , int d){

    int start = getdate(y , m , 1);
    return (d - (7 - start) - 1) / 7 + 2;

}

int main(){

    IO

    string s;
    int rou[7];

    cin >> s;
    for(int i=0; i<7; i++){

        char c;
        cin >> c;
        if(c == 'b') rou[i] = 1;
        else rou[i] = 0; 

    }

    int y = stoi(s.substr(0 , 4)) , m = stoi(s.substr(5 , 7)) , d = stoi(s.substr(8 , 10));

    int date = getdate(y , m , d) , week = getweek(y , m , d);

    cout << day[(date + 6) % 7] << '\n';

    cout << "------------" << y << "," << month[m - 1] << "(Week " << week << ")";
    for(int i=0; i<18-len[m - 1]; i++) cout << "-";
    cout << '\n';

    cout << "|  Sun|  Mon|  Tue|  Wed|  Thu|  Fri|  Sat|\n";

    int cur = d , ind = 0;

    cout << "|";
    for(int i=0; i<7; i++){

        cout << "   ";

        if(i >= date % 7) cout << setw(2) << right << cur , cur++;
        else cout << "  ";

        cout << "|";

        if(isdd(y) && cur > dd_of_m[m - 1]) cur = 1;
        else if(!isdd(y) && cur > d_of_m[m - 1]) cur = 1;
        
    }
    cout << '\n';

    cout << "|";
    for(int i=0; i<7; i++){

        cout << " ";

        if(i >= date % 7){

            if(rou[ind] == 1) cout << "busy";
            else cout << "free";

            ind++;

        }else cout << "    ";

        cout << "|";

        if(isdd(y) && cur > dd_of_m[m - 1]) cur = 1;
        else if(!isdd(y) && cur > d_of_m[m - 1]) cur = 1;

    }
    cout <<'\n';

    if(ind < 7){

        cout << "|";
        for(int i=0; i<7; i++){

            cout << "   ";

            if(i < date % 7) cout << setw(2) << right << cur , cur++;
            else cout << "  ";

            cout << "|";

            if(isdd(y) && cur > dd_of_m[m - 1]) cur = 1;
            else if(!isdd(y) && cur > d_of_m[m - 1]) cur = 1;

        }
        cout <<'\n';

        cout << "|";
        for(int i=0; i<7; i++){

            cout << " ";

            if(i < date % 7){

                if(rou[ind] == 1) cout << "busy";
                else cout << "free";

                ind++;

            }else cout << "    ";

            cout << "|";

            if(isdd(y) && cur > dd_of_m[m - 1]) cur = 1;
            else if(!isdd(y) && cur > d_of_m[m - 1]) cur = 1;

        }
        cout << '\n';

    }

    cout << "-------------------------------------------\n";

    return 0;

}