#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a , string b){

    int la = a.length() , lb = b.length();

    if(la > lb) return true;
    if(la < lb) return false;

    for(int i=0; i<la; i++){

        if(a[i] > b[i]) return true;
        else if(a[i] < b[i]) return false;

    }

    return true;

}

string add(string a , string b){

    if(compare(b , a)) swap(a , b);
    int la = a.length() , lb = b.length();

    a = '0' + a;
    for(int i=0; i<=la-lb; i++) b = '0' + b;

    string temp = a;

    for(int i=la; i>0; i--){

        int s = (temp[i] + b[i] - 96) % 10 , co = (temp[i] + b[i] - 96) / 10;

        temp[i] = (char)(s + 48);
        temp[i-1] += co;

    }

    return temp;

}

string subtract(string a , string b){

    if(compare(b , a)) swap(a , b);
    int la = a.length() , lb = b.length();

    for(int i=0; i<la-lb; i++) b = '0' + b;

    string ans;

    for(int i=0; i<la; i++) ans += '0';

    for(int i=la-1; i>=0; i--){

        if(a[i] >= b[i]) ans[i] += (int)(a[i] - b[i]);
        else{

            a[i - 1]--;
            ans[i] += (int)(a[i] - b[i] + 10);

        }

    }

    return ans;

}

string multiply(string a , string b){

    string ans = "0";

    if(compare(b , a)) swap(a , b);
    int la = a.length() , lb = b.length();

    for(int i=lb-1; i>=0; i--){

        string temp = "0";

        int dig = (int)(b[i] - 48);

        for(int j=la-1; j>=0; j--){

            string m = to_string((int)(a[j] - 48) * dig);

            for(int k=0; k<la-j-1; k++) m += '0';

            temp = add(temp , m);

        }

        for(int j=0; j<lb-i-1; j++) temp += '0';

        ans = add(ans , temp);

    }

    return ans;

}

string divide(string a , string b){

    string ans;

    a = "0" + a;

    int la = a.length() , lb = b.length();

    for(int i=la-lb; i>=1; i--){

        ans += "0" ;
        int lans = ans.length();

        while(compare(a.substr(la - lb - i , lb + 1) , "0" + b)){

            a = a.substr(0 , la - lb - i) + subtract(a.substr(la - lb - i , lb + 1) , "0" + b) + a.substr(la - i + 1 , i);
            ans[lans - 1]++;

        }

    }

    return ans;

}

string modulo(string a , string b){

    string ans;

    a = "0" + a;

    int la = a.length() , lb = b.length();

    for(int i=la-lb; i>=1; i--){

        ans += "0" ;
        int lans = ans.length();

        while(compare(a.substr(la - lb - i , lb + 1) , "0" + b)){

            a = a.substr(0 , la - lb - i) + subtract(a.substr(la - lb - i , lb + 1) , "0" + b) + a.substr(la - i + 1 , i);
            ans[lans - 1]++;

        }

    }

    return a;

}

string modify(string ans){

    int lans = ans.length() , i;

    for(i=0; i<lans; i++){

        if(ans[i] != '0'){

            ans = ans.substr(i , lans - i);
            break;

        }

    }

    if(i == lans) ans = "0";
    return ans;

}

class LargeNumber
{
    friend std::ostream& operator<<(std::ostream &o, const LargeNumber &n){

        o << n.num;
        return o;

    }

public:

    string num;

    LargeNumber(const std::string& k){ num = k; }

    LargeNumber operator+(LargeNumber& rhs){

        string ans = add(num , rhs.num);
        ans = modify(ans);

        return ans;

    }

    LargeNumber operator-(LargeNumber& rhs){

        string ans = subtract(num , rhs.num);
        ans = modify(ans);
        if(compare(rhs.num , num) && ans != "0") ans = '-' + ans;

        return ans;

    }

    LargeNumber operator*(LargeNumber& rhs){

        string ans = multiply(num , rhs.num);
        ans = modify(ans);

        return ans;

    }

    LargeNumber operator/(LargeNumber& rhs){

        string ans = divide(num , rhs.num);
        ans = modify(ans);

        return ans;

    }

    LargeNumber operator%(LargeNumber& rhs){

        string ans = modulo(num , rhs.num);
        ans = modify(ans);

        return ans;

    }

};