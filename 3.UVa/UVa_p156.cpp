#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

#define IO ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define pb push_back

using namespace std;

vector< multiset<char> > dic;
vector<string> voc;
vector<int> era;

int main(){

    IO

    string s;

    while(cin >> s && s != "#"){

        multiset<char> temp;

        int l = s.length();

        for(int i=0; i<l; i++) temp.insert(tolower(s[i]));

        int cnt = 0;

        for(int i=0; i<(int)dic.size(); i++){

            if(dic[i].size() != temp.size()){

                cnt++;
                continue;

            }

            bool check = true;

            for(multiset<char>::iterator itt = temp.begin() , itd = dic[i].begin(); itt!=temp.end(); itt++ , itd++){

                if(*itt != *itd){

                    check = false;
                    cnt++;
                    break;

                }

            }

            if(check){

                era.pb(i);
                i = dic.size();

                break;

            } 

        }

        if(cnt == (int)dic.size()) dic.pb(temp) , voc.pb(s);

    }

    sort(era.begin() , era.end());

    for(int i=(int)era.size()-1; i>=0; i--) if(i == (int)era.size() - 1 || era[i] != era[i + 1]) voc.erase(voc.begin() + era[i]);

    sort(voc.begin() , voc.end());

    for(int i=0; i<(int)voc.size(); i++) cout << voc[i] << '\n';

    return 0;

}