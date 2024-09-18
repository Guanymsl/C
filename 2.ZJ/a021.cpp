#include <iostream>
#include <cstring>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

using namespace std;

const int N = 1e4+5;

int a[N] , b[N] , car[N] , ans[N] , temp[N];

int main(){

    string s;

    while(getline(cin,s)){

        for(int i=0; i<N; i++) a[i] = b[i] = car[i] = ans[i] = temp[i]= 0;
        
        int l = s.length() , ind = 0 , op , i , neg = 0;

        for(i=l-1; i>=0; i--){

            if(s[i] == ' ') break;

            b[ind] = (int)(s[i]-'0') , ind++;

        }

        int ma = i-3 , mb = l-i-2;
        int m = max(ma , mb);

        i--;
        ind = 0;

        if(s[i] == '+') op = 1;
        else if(s[i] == '-') op = 2;
        else if(s[i] == '*') op = 3;
        else if(s[i] == '/') op = 4;

        i = i-2;

        for(int j=i;j>=0;j--) a[ind] = (int)(s[j]-'0') , ind++;

        if(op == 1){

            for(int i=0; i<=m+1; i++){

                ans[i] = (car[i] + a[i] + b[i]) % 10;
                car[i+1] = (car[i] + a[i] + b[i]) / 10;

            }

        }else if(op == 2){

            int cnt = 0;

            if(ma == mb){

                for(int i=m; i>=0; i--){

                    if(a[i] > b[i]) break;

                    if(a[i] < b[i]){

                        cnt = 1;
                        break;

                    }

                }

            }

            if(ma < mb || (ma == mb && cnt)){

                for(int i=0; i<=m; i++) swap(a[i] , b[i]);

                swap(ma , mb);

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

            for(int i=0; i<=mb; i++){

                for(int j=0; j<=ma+1; j++){

                    temp[i+j] = (a[j] * b[i] + car[i+j]) % 10;
                    car[i+j+1] = (a[j] * b[i] + car[i+j]) / 10;
                    
                }

                memset(car , 0 , N);

                for(int j=0; j<=ma+1; j++){

                    car[i+j+1] = (ans[i+j] + temp[i+j] + car[i+j]) / 10;
                    ans[i+j] = (ans[i+j] + temp[i+j] + car[i+j]) % 10;
                    
                }

                memset(car , 0 , N);
                memset(temp , 0 , N);

            }

        }else if(op == 4){

            int cnt = 0;

            if(ma == mb){

                for(int i=m; i>=0; i--){

                    if(a[i] > b[i]) break;

                    if(a[i] < b[i]){

                        cnt = 1;
                        break;

                    }

                }

            }

            if(ma >= mb && (ma != mb || cnt == 0)){

                for(int i=ma-mb; i>=0; i--){

                    int add = 0;

                    while(1){

                        if(a[i+mb+1] == 0){

                            for(int j=mb; j>=0; j--){

                                if(a[i+j] > b[j]) break;

                                if(a[i+j] < b[j]){

                                    add = 1;
                                    break;

                                }

                            }

                        }

                        if(add == 1) break;

                        for(int j=0; j<=mb+1; j++){

                            if(a[i+j] - b[j] + car[i+j] < 0){

                                a[i+j] = (10 + a[i+j] - b[j]) + car[i+j];
                                car[i+j+1] = -1;

                            }

                            else a[i+j] = a[i+j] - b[j] + car[i+j];

                        }

                        ans[i]++;

                        memset(car , 0 , N);

                    }

                }

            }

        }

        int ln = m * m + 1;
 
        int st = -1;

        for(int i = ln; i >= 0; i--){

            if(ans[i] != 0){

                st = i;
                break;

            }

        }

        if(st < 0) cout << 0;

        if(neg == 1) cout << "-";

        for(int j=st; j>=0; j--) cout << ans[j];

        cout << '\n';

    }

    return 0;

}