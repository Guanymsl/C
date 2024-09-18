#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 1e6+5;

int a[N] , b[N] , car[N] , ans[N] , temp[N];

int main(){

    string s1 , s2 , s3;
    cin >> s1 >> s2 >> s3;
    
    for(int i=0; i<N; i++) a[i] = b[i] = car[i] = ans[i] = temp[i] = 0;
        
    int l1 = s1.length() , l2 = s2.length() , neg = 0 , op;

    if(s3 == "+") op = 1;
    else if(s3 == "-") op = 2;
    else if(s3 == "*") op = 3;

    int ind = 0;

    for(int i=l1-1; i>=0; i--) a[ind] = (int)(s1[i]-'0') , ind++;

    ind = 0;

    for(int i=l2-1; i>=0; i--) b[ind] = (int)(s2[i]-'0') , ind++;

    l1-- , l2--;

    int m = max(l1 , l2);

    if(op == 1){

        for(int i=0; i<=m+1; i++){

            ans[i] = (car[i] + a[i] + b[i]) % 10;
            car[i+1] = (car[i] + a[i] + b[i]) / 10;

        }

    }else if(op == 2){

        int cnt = 0;

        if(l1 == l2){

            for(int i=m; i>=0; i--){

                if(a[i] > b[i]) break;

                if(a[i] < b[i]){

                    cnt = 1;
                    break;

                }

            }

        }

        if(l1 < l2 || (l1 == l2 && cnt)){

            for(int i=0; i<=m; i++) swap(a[i] , b[i]);

            swap(l1 , l2);

            neg = 1;

        }
              
        for(int i=0; i<=m; i++){

            if(a[i] - b[i] + car[i] < 0){

                ans[i] = (10 + a[i] - b[i]) + car[i];
                car[i+1] = -1;

            }

            else ans[i] = a[i] - b[i] + car[i];

        }

    }else if(op == 3){

        for(int i=0; i<=l2; i++){

            for(int j=0; j<=l1+1; j++){

                temp[i+j] = (a[j] * b[i] + car[i+j]) % 10;
                car[i+j+1] = (a[j] * b[i] + car[i+j]) / 10;
                    
            }

            memset(car , 0 , N);

            for(int j=0; j<=l1+1; j++){

                car[i+j+1] = (ans[i+j] + temp[i+j] + car[i+j]) / 10;
                ans[i+j] = (ans[i+j] + temp[i+j] + car[i+j]) % 10;
                    
            }

            memset(car , 0 , N);
            memset(temp , 0 , N);

        }

    }
        
    int ln = N , st = -1;

    for(int i=ln; i>=0; i--){

        if(ans[i] != 0){

            st = i;
            break;

        }

    }

    if(st < 0) cout << 0;

    if(neg == 1) cout << "-";

    for(int i=st; i>=0; i--) cout << ans[i];

    cout << '\n';

    return 0;

}