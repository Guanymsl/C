#include <iostream>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

int pic[45][85] , mor[45][85];

void print(int pix[][85]){

    for(int i=0; i<40; i++){

        for(int j=0; j<80; j++) cout << (pix[i][j] ? "*" : " ");
        cout << '\n';

    }

}

void morph(){

    for(int i=0; i<40; i++){

        for(int j=0; j<80; j++){

            if(i == 0 || j == 0 || i == 39 || j == 79) mor[i][j] = pic[i][j];
            else{

                mor[i][j] = 0;

                for(int it=-1; it<=1; it++){

                    for(int jt=-1; jt<=1; jt++) mor[i][j] += pic[i + it][j + jt];

                }

            }

        }

    }

}

void erosion(){

    for(int i=1; i<39; i++){

        for(int j=1; j<79; j++){

            if(mor[i][j] == 9) mor[i][j] = 1;
            else mor[i][j] = 0;
        }

    }

}

void dilation(){

    for(int i=1; i<39; i++){

        for(int j=1; j<79; j++){

            if(mor[i][j] >= 1) mor[i][j] = 1;
            else mor[i][j] = 0;
        }

    }

}

int main(){

    IO

    int thres , type;
    cin >> thres >> type;

    for(int i=0; i<40; i++){

        for(int j=0; j<80; j++){

            cin >> pic[i][j];

            if(pic[i][j] >= thres) pic[i][j] = 1;
            else pic[i][j] = 0;

        }

    }

    
    if(type == 0) print(pic);
    else if(type == 1){

        morph();
        erosion();
        print(mor);

    }else{

        morph();
        dilation();
        print(mor);

    }

    return 0;

}